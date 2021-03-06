
/********************************\
#   THE REACTION GAME            #
#   main.cpp                     #
#                                #
#   Authors:                     #
#       KEMPERLE Andreas         #
#       WINKLER  Andreas         #
#                                #
#   created: 2018/04/18          #
#   Version: 2018/05/28 - V6.11  #
\********************************/


// ===============================================================
// INCLUDES

#include "piproxy.h"			// includes depending on target platform (Pi/PC)
#include <iostream>				// used for writing to console
#include <chrono>				// used for timing

#include "main.hpp"				// constexpressions, enums
#include "IncludeJsonData.hpp"
#include "IPlayer.hpp"
#include "Player.hpp"
#include "IoManager.hpp"
#include "IDigitalOutput.hpp"
#include "DigitalInput.hpp"
#include "DigitalOutput.hpp"


// ===============================================================
// DEFINES

// #define USING_INVERTED_LOGIC


// ===============================================================
// CONSTANTS

#ifdef USING_INVERTED_LOGIC
const bool pushed = false;
const bool not_pushed = true;
#else
const bool pushed = true;
const bool not_pushed = false;
#endif


// ===============================================================
// GLOBAL VARIABLES

nlohmann::json pins_config;


// ===============================================================
// PROTOTYPES

short setup_game(IPlayer& player_1, IPlayer& player_2);
Winner game(IPlayer& player_1, IPlayer& player_2, short game_rounds, const IDigital_output& game_led, const IDigital_output& buzzer);
void end_of_game(Winner winner, IPlayer& player_1, IPlayer& player_2);
void who_won_round(const Winner round_winner, IPlayer& player_1, IPlayer& player_2);
void prepare_round(const IDigital_output& buzzer);


// #################################### SECTION BREAK ####################################


// ===============================================================
// MAIN FUNCTION

int main(void)
{
	Io_manager pi_manager;

	auto winner = Winner::tie;
	short game_rounds = 0;

	try
	{
		Digital_output buzzer{ pi_manager, get_pins()["buzzer"].get<pin>() };
		Digital_output game_led{ pi_manager,get_pins()["game_led"].get<pin>() };
#ifndef USING_INVERTED_LOGIC
		Digital_input player_1_button{ pi_manager, get_pins()["player_1_button"].get<pin>(), Resistor::pulldown };
		Digital_input player_2_button{ pi_manager, get_pins()["player_2_button"].get<pin>(), Resistor::pulldown };
#else
		Digital_input player_1_button{ pi_manager, get_pins()["player_1_button"].get<pin>(), Resistor::pullup };
		Digital_input player_2_button{ pi_manager, get_pins()["player_2_button"].get<pin>(), Resistor::pullup };
#endif
		Digital_output player_1_led{ pi_manager,get_pins()["player_1_led"].get<pin>() };
		Digital_output player_2_led{ pi_manager,get_pins()["player_2_led"].get<pin>() };

		Player player_1{ player_1_button.get_pin(), player_1_led.get_pin(), "P1", 0 };
		Player player_2{ player_2_button.get_pin(), player_2_led.get_pin(), "P2", 0 };


		game_rounds = setup_game(player_1, player_2);
		winner = game(player_1, player_2, game_rounds, game_led, buzzer);
		end_of_game(winner, player_1, player_2);
	}
	catch (std::runtime_error& exception)
	{
		std::cerr << "Exception was thrown: " << exception.what() << std::endl;
	}
	catch(std::logic_error& exception)
	{
		std::cerr << "Exception was thrown: " << exception.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "An unknown error occured!" << std::endl;
	}

	getchar();
	getchar();
	return 0;
}


// #################################### SECTION BREAK ####################################


// ===============================================================
// LOOP FUNCTION

Winner game(IPlayer& player_1, IPlayer& player_2, short game_rounds, const IDigital_output& game_led, const IDigital_output& buzzer)
{
	static unsigned short act_round = 0;

	while(act_round < game_rounds)
	{
		int64_t start_time_us = 0;
		unsigned short timeout = 0;
		unsigned short random_t = 0;
		auto round_winner = Winner::tie;
		
		digitalWrite(game_led.get_pin(), pushed);
		random_t = rand() % 5000 + 5000; // to activate between 5-10 seconds
		timeout = random_t + max_time_inactive;

		prepare_round(buzzer);
		std::cout << "\n\t Start of Round " << act_round + 1 << "!\n" << std::endl;
		
		auto now = std::chrono::system_clock::now().time_since_epoch();
		start_time_us = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();


		while (true)
		{
			now = std::chrono::system_clock::now().time_since_epoch();
			const auto delta = std::chrono::duration_cast<std::chrono::milliseconds>(now).count() - start_time_us;

			if (delta >= timeout)
			{
				if (player_1.read_wins() > player_2.read_wins())
					return Winner::p1;
				else if (player_1.read_wins() < player_2.read_wins())
					return Winner::p2;
				else if ((player_1.read_wins() == player_2.read_wins()))
					return Winner::tie;
				else
					return Winner::timeout;
			}
			else if (delta >= random_t)
			{
				if (!digitalRead(game_led.get_pin()))
					digitalWrite(game_led.get_pin(), HIGH);

				if (player_1.read_button_state() == pushed)
				{
					round_winner = Winner::p1;
					player_1.add_victory();
					break;
				}
				else if (player_2.read_button_state() == pushed)
				{
					round_winner = Winner::p2;
					player_2.add_victory();
					break;
				}
			}
			else
			{
				if (player_1.read_button_state() == pushed)
				{
					round_winner = Winner::p2;
					player_2.add_victory();
					break;
				}
				else if (player_2.read_button_state() == pushed)
				{
					round_winner = Winner::p1;
					player_1.add_victory();
					break;
				}
			}
			delay(1);
		}
		digitalWrite(game_led.get_pin(), LOW);
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

void who_won_round(const Winner round_winner, IPlayer& player_1, IPlayer& player_2)
{
	if ((round_winner == Winner::p1) || (round_winner == Winner::p2))
		std::cout << "\nWinner is Player " << round_winner << "!" << std::endl;
	else
		std::cout << "\nBoth players won in this round!" << std::endl;

	if (round_winner == Winner::p1)
	{
		player_1.set_led_state(true);
		delay(led_winner_time);
		player_1.set_led_state(false);
	}
	else if(round_winner == Winner::p2)
	{
		player_2.set_led_state(true);
		delay(led_winner_time);
		player_2.set_led_state(false);
	}
	else
	{
		player_1.set_led_state(true);
		player_2.set_led_state(true);
		delay(led_winner_time);
		player_1.set_led_state(false);
		player_2.set_led_state(false);
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

	default: 
		break;
	}
}


// ===============================================================
// FUNCTION FOR PREPARING EVERY ROUND

void prepare_round(const IDigital_output& buzzer)
{
	digitalWrite(buzzer.get_pin(), HIGH);
	delay(150);
	digitalWrite(buzzer.get_pin(), LOW);
	delay(250);
	digitalWrite(buzzer.get_pin(), HIGH);
	delay(150);
	digitalWrite(buzzer.get_pin(), LOW);
	delay(250);
	digitalWrite(buzzer.get_pin(), HIGH);
	delay(400);
	digitalWrite(buzzer.get_pin(), LOW);
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
	}

	return game_rounds;
}