
/********************************
#   THE REACTION GAME           #
#   Game.hpp                    #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/14         #
#   Version: 2018/05/28 - V1.2  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "Player.hpp"
#include "IDigitalOutput.hpp"
#include "main.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// GAME CLASS

class Game
{
public:
	Game();
	Game(Player player_1, Player player_2, short game_rounds, Winner winner, IDigital_output& buzzer);
	void setup(Player player_1, Player player_2);
	void prepare_round() const;
	void announce_winner(IPlayer& player_1, IPlayer& player_2) const;
	void end() const;

	~Game();

private:
	Player player_1_;
	Player player_2_;
	Winner round_winner_;
	short game_rounds_;
	IDigital_output& buzzer_;
};