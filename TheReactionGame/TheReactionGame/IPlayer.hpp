
/********************************
#   THE REACTION GAME           #
#   IPlayer.h                   #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/04/18         #
#   Version: 2018/05/02 - V4.1  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include <iostream>


// #################################### SECTION BREAK ####################################


// ===============================================================
// INTERFACE

class IPlayer
{
public:
	// --------- --------- --------- ---------
	virtual void set_name(std::string name) = 0;
	virtual std::string read_name() const = 0;
	// --------- --------- --------- ---------
	virtual void set_wins(unsigned short wins) = 0;
	virtual unsigned short read_wins(void) const = 0;
	virtual void add_victory(void) = 0;
	// --------- --------- --------- ---------
	virtual unsigned short read_button_pin(void) const = 0;
	// ---------
	virtual bool read_button_state(void) const = 0;
	// --------- --------- --------- ---------
	virtual void set_led_pin(unsigned short led_pin) = 0;
	virtual unsigned short read_led_pin(void) const = 0;
	// ---------
	virtual void set_led_state(bool led_state) = 0;
	virtual bool read_led_state(void) const = 0;
	// --------- --------- --------- ---------

	virtual ~IPlayer() = 0;
};
