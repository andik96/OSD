
/********************************\
#   THE REACTION GAME            #
#   main.cpp                     #
#                                #
#   Authors:                     #
#       KEMPERLE Andreas         #
#       WINKLER  Andreas         #
#                                #
#   created: 2018/04/18          #
#   Version: 2018/05/14 - V6.7   #
\********************************/


// ===============================================================
// INCLUDES

#include "piproxy.h"
#include <iostream>		// used for writing to console
#include <chrono>
#include "IncludeJsonData.hpp"
#include "IPlayer.hpp"
#include "Player.hpp"
#include "main.hpp"
#include "IoManager.hpp"
//#include "Game.hpp"

// ===============================================================
// DEFINES

constexpr unsigned short max_game_rounds = 30;
constexpr unsigned short max_time_inactive = 3000;
constexpr unsigned short led_winner_time = 3000;


// ===============================================================
// GLOBAL VARIABLES

nlohmann::json pins_config;
int buzzer;
int game_led;
unsigned short player_1_button;
unsigned short player_2_button;
unsigned short player_1_led;
unsigned short player_2_led;


// ===============================================================
// PROTOTYPES

void setup_pi(IPlayer& player_1, IPlayer& player_2);
short setup_game(IPlayer& player_1, IPlayer& player_2);
Winner game(IPlayer& player_1, IPlayer& player_2, short game_round);
void end_of_game(Winner winner, IPlayer& player_1, IPlayer& player_2);
void who_won_round(Winner round_winner, IPlayer& player_1, IPlayer& player_2);
void prepare_round(void);


// #################################### SECTION BREAK ####################################



// ===============================================================
// MAIN FUNCTION

int main(void)
{
	buzzer = get_pins()["buzzer"].get<int>();
	game_led = get_pins()["game_led"].get<int>();
	player_1_button = get_pins()["player_1_button"].get<unsigned short>();
	player_2_button = get_pins()["player_2_button"].get<unsigned short>();
	player_1_led = get_pins()["player_1_led"].get<unsigned short>();
	player_2_led = get_pins()["player_2_led"].get<unsigned short>();

	Player player_1{ player_1_button, player_1_led, "P1", 0 };
	Player player_2{ player_2_button, player_2_led, "P2", 0 };
	//Game Game();
	Winner winner = tie;
	short game_rounds = 0;


	setup_pi(player_1, player_2);
	game_rounds = setup_game(player_1, player_2);
	winner = game(player_1, player_2, game_rounds);
	end_of_game(winner, player_1, player_2);

	return 0;
}


// #################################### SECTION BREAK ####################################


// ===============================================================
// SETUP FUNCTION

void setup_pi(IPlayer& player_1, IPlayer& player_2)
{
	wiringPiSetup();

	// initialize all in- and outputs here
	pinMode(buzzer, OUTPUT);
	pinMode(game_led, OUTPUT);
	pinMode(player_1.read_led_pin(), OUTPUT);
	pinMode(player_2.read_led_pin(), OUTPUT);

	pinMode(player_1.read_button_pin(), INPUT);
	pinMode(player_2.read_button_pin(), INPUT);
	pullUpDnControl(player_1.read_button_pin(), PUD_DOWN);
	pullUpDnControl(player_2.read_button_pin(), PUD_DOWN);
}


// ===============================================================
// LOOP FUNCTION

Winner game(IPlayer& player_1, IPlayer& player_2, short game_rounds)
{
	static unsigned short act_round = 0;

	while(act_round < game_rounds)
	{
		int64_t start_time_us = 0;
		unsigned short timeout = 0;
		unsigned short random_t = 0;
		bool game_led_on = false;
		Winner round_winner = tie;
		
		digitalWrite(game_led, LOW);
		random_t = rand() % 5000 + 5000; // to activate between 5-10 seconds
		timeout = random_t + max_time_inactive;

		prepare_round();
		std::cout << "\n\t Start of Round " << act_round + 1 << "!\n" << std::endl;
		
		auto now = std::chrono::system_clock::now().time_since_epoch();
		start_time_us = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();


		while (true)
		{
			now = std::chrono::system_clock::now().time_since_epoch();
			auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now).count() - start_time_us;

			if (delta >= timeout)
			{
				return Winner::timeout;
			}
			else if (delta >= random_t)
			{
				if (!digitalRead(game_led))
					digitalWrite(game_led, HIGH);

				if (player_1.read_button_state() == LOW)
				{
					round_winner = p1;
					player_1.add_victory();	//player_1.setWins(player_1.readWins() + 1);
					break;
				}
				else if (player_2.read_button_state() == LOW)
				{
					round_winner = p2;
					player_2.add_victory();	//player_2.setWins(player_2.readWins() + 1);
					break;
				}
			}
			else
			{
				if (player_1.read_button_state() == LOW)
				{
					round_winner = p2;
					player_2.add_victory();	//player_2.setWins(player_2.readWins() + 1);
					break;
				}
				else if (player_2.read_button_state() == LOW)
				{
					round_winner = p1;
					player_1.add_victory();	//player_1.setWins(player_1.readWins() + 1);
					break;
				}
			}
			delay(1);
		}
		digitalWrite(game_led, LOW);
		who_won_round(round_winner, player_1, player_2);

		if (player_1.read_wins() > game_rounds / 2)
			return Winner::p1;
		else if (player_2.read_wins() > game_rounds / 2)
			return Winner::p2;
		act_round++;
	}

	return Winner::tie;
}


// #################################### SECTION BREAK ####################################


// ===============================================================
// FUNCTION FOR SHOWING, WHO WON THE ACTUAL ROUND

void who_won_round(Winner winner, IPlayer& player_1, IPlayer& player_2)
{
	std::cout << "\nWinner is Player " << winner << "!" << std::endl;
	if (winner == 1)
	{
		player_1.set_led_state(TRUE);
		delay(led_winner_time);
		player_1.set_led_state(FALSE);
	}
	else
	{
		player_2.set_led_state(TRUE);
		delay(led_winner_time);
		player_2.set_led_state(FALSE);
	}
}


// ===============================================================
// END OF GAME FUNCTION

void end_of_game(Winner winner, IPlayer& player_1, IPlayer& player_2)
{
	switch (winner)
	{
	case Winner::tie:
		std::cout << "Game ended in a tie" << std::endl;
		break;

	case Winner::p1:
		std::cout << "Player 1 has won the game with " << player_1.read_wins() << " wins." << std::endl;
		break;

	case Winner::p2:
		std::cout << "Player 2 has won the game with " << player_2.read_wins() << " wins." << std::endl;
		break;

	case Winner::timeout:
		std::cout << "Timeout - game aborted" << std::endl;
		break;

	default: break;

	}
}


// ===============================================================
// FUNCTION FOR PREPARING EVERY ROUND

void prepare_round()
{
	digitalWrite(buzzer, HIGH);
	delay(150);
	digitalWrite(buzzer, LOW);
	delay(250);
	digitalWrite(buzzer, HIGH);
	delay(150);
	digitalWrite(buzzer, LOW);
	delay(250);
	digitalWrite(buzzer, HIGH);
	delay(400);
	digitalWrite(buzzer, LOW);
}

// ===============================================================
// FUNCTION FOR GAME SETUP

short setup_game(IPlayer& player_1, IPlayer& player_2)
{
	static unsigned short game_rounds = 255;
	std::string input_stream;

	// ASK FOR PLAYER NAMES
	std::cout << "Player 1, please enter your unique name!\n\t" << std::endl;
	std::cin >> input_stream;
	player_1.set_name(input_stream);

	do {
		std::cout << "Player 2, please enter your unique name!\n\t" << std::endl;
		std::cin >> input_stream;
		player_2.set_name(input_stream);
	} while (player_2.read_name() == player_1.read_name());

	// ASK FOR GAME ROUNDS
	while (game_rounds > max_game_rounds)
	{
		std::cout << "\n\t How many rounds do you want to play?\n\t " << std::endl;
		std::cin >> game_rounds;
		// cin.fail() or if(game_rounds) to catch non-int input
	}

	return game_rounds;
}