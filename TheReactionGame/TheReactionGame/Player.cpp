
/********************************
#   THE REACTION GAME           #
#   Player.cpp                  #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/04/18         #
#   Version: 2018/05/02 - V4.1  #
********************************/


// ===============================================================
// INCLUDES

#include <iostream>
#include "piproxy.h"
#include "Player.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// CONSTRUCTOR

Player::Player() // MFA button_pin_, led_pin_, wins_ and current_led_state_ are not initialized. they are undefined, which is dangerous
{
}

// ===============================================================
// DECLARE CLASS PLAYER

Player::Player(unsigned short button_pin, unsigned short led_pin, std::string name, unsigned short wins) 
	: button_pin_{ button_pin }, led_pin_{ led_pin }, wins_{ wins }, name_{ name }
{
}


// #################################### SECTION BREAK ####################################


// ===============================================================
// METHODS

void Player::set_name(std::string name)
{
	this->name_ = name;
}

std::string Player::read_name(void) const
{
	return this->name_;
}
// --------- --------- --------- ---------
void Player::set_wins(unsigned short wins)
{
	this->wins_ = wins;
}
unsigned short Player::read_wins(void) const
{
	return this->wins_;
}

void Player::add_victory(void)
{
	Player::set_wins(Player::read_wins() + 1);
}

// --------- --------- --------- ---------
unsigned short Player::read_button_pin(void) const
{
	return this->button_pin_;
}
// ---------
bool Player::read_button_state(void) const
{
	return digitalRead(this->read_button_pin());
}
// --------- --------- --------- ---------
void Player::set_led_pin(unsigned short led_pin)
{
	this->led_pin_ = led_pin;
}

unsigned short Player::read_led_pin(void) const
{
	return this->led_pin_;
}
// ---------
void Player::set_led_state(bool led_state)
{
	digitalWrite(this->read_led_pin(), led_state);
}

bool Player::read_led_state(void) const
{
	return digitalRead(this->read_led_pin());
}
// --------- --------- --------- ---------