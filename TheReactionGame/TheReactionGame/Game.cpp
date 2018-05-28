
/********************************
#   THE REACTION GAME           #
#   Game.cpp                    #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/14         #
#   Version: 2018/05/28 - V1.2  #
********************************/


// ===============================================================
// INCLUDES

#include "main.hpp"
#include "Game.hpp"
#include "piproxy.h"			// includes depending on target platform (Pi/PC)
#include <iostream>				// used for writing to console
#include "IncludeJsonData.hpp"
#include "IPlayer.hpp"
#include "Player.hpp"
#include "IDigitalOutput.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// CONSTRUCTOR AND INITIALISER LIST

Game::Game(Player player_1, Player player_2, short game_rounds, Winner round_winner, IDigital_output& buzzer) :
	player_1_{player_1}, player_2_{ player_2 }, game_rounds_{game_rounds}, round_winner_{round_winner}, buzzer_{buzzer}
{
	setup(player_1, player_2);
}


// ===============================================================
// SETUP GAME FUNCTION

void Game::setup(Player player_1, Player player_2)
{
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

}

// ===============================================================
// PREPARE ROUND FUNCTION

void Game::prepare_round() const
{
	digitalWrite(buzzer_.get_pin(), HIGH);
	delay(150);
	digitalWrite(buzzer_.get_pin(), LOW);
	delay(250);
	digitalWrite(buzzer_.get_pin(), HIGH);
	delay(150);
	digitalWrite(buzzer_.get_pin(), LOW);
	delay(250);
	digitalWrite(buzzer_.get_pin(), HIGH);
	delay(400);
	digitalWrite(buzzer_.get_pin(), LOW);
}

// ===============================================================
// FUNCTION FOR SHOWING, WHO WON THE ACTUAL ROUND

void Game::announce_winner(IPlayer& player_1, IPlayer& player_2) const
{
	std::cout << "\nWinner is Player " << round_winner_ << "!" << std::endl;
	if (this->round_winner_ == Winner::p1)
	{
		player_1.set_led_state(true);
		delay(led_winner_time);
		player_1.set_led_state(false);
	}
	else
	{
		player_2.set_led_state(true);
		delay(led_winner_time);
		player_2.set_led_state(false);
	}
}

// ===============================================================
// END OF GAME FUNCTION

void Game::end() const
{
	switch (round_winner_)
	{
		case Winner::tie:
			std::cout << "Game ended in a tie" << std::endl;
			break;

		case Winner::p1:
			std::cout << "Player 1 has won the game with " << player_1_.read_wins() << " wins." << std::endl;
			break;

		case Winner::p2:
			std::cout << "Player 2 has won the game with " << player_2_.read_wins() << " wins." << std::endl;
			break;

		case Winner::timeout:
			std::cout << "Timeout - game aborted" << std::endl;
			break;

		default: 
			break;
	}
}


// ===============================================================
// DESTRUCTOR

Game::~Game()
{
}
