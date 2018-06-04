
/********************************
#   THE REACTION GAME           #
#   Player.h                    #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/04/18         #
#   Version: 2018/05/20 - V5.0  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include <iostream>
#include "IPlayer.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// DECLARE CLASS FOR DIGITAL INPUT

class Player : public IPlayer
{
public:
	Player();
	Player(pin button_pin, pin led_pin, std::string name, unsigned short wins);

	// --------- --------- --------- ---------
	void set_name(std::string name) override;
	std::string read_name(void) const override;
	// --------- --------- --------- ---------
	void set_wins(unsigned short wins) override;
	unsigned short read_wins(void) const override;
	void add_victory(void) override;
	// --------- --------- --------- ---------
	pin read_button_pin(void) const override;
	// ---------
	bool read_button_state(void) const override;
	// --------- --------- --------- ---------
	void set_led_pin(pin led_pin) override;
	pin read_led_pin(void) const override;
	// ---------
	void set_led_state(bool led_state) override;
	bool read_led_state(void) const override;
	// --------- --------- --------- ---------


private:
	pin button_pin_;
	std::string name_;
	unsigned short wins_;
	pin led_pin_;
};