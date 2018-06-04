
/********************************
#   THE REACTION GAME           #
#   IoManager.hpp               #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/02         #
#   Version: 2018/05/24 - V2.3  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "json.hpp"
#include "piproxy.h"


// ===============================================================
// TYPEDEFS

using pin = std::uint_fast8_t;


// ===============================================================
// ENUMS

enum class Resistor
{
	pulldown = PUD_DOWN,
	no_resistor = PUD_OFF,
	pullup = PUD_OFF
};


// #################################### SECTION BREAK ####################################


// ===============================================================
// DECLARE CLASS FOR MANAGING IO-PINS

class Io_manager
{
public:
	Io_manager();													// here the pin will be reserved
	Io_manager(const Io_manager & other) = delete;					// you are not allowed to copy any pin!
	Io_manager(Io_manager && other) = delete;						// no move action allowed!
	Io_manager& operator = (const Io_manager& rhs) = delete;		// you are not allowed to copy any pin!
	Io_manager& operator = (Io_manager&& rhs) = delete;				// no move action allowed!
	~Io_manager();													// here the pin will be released again

	void reserve(const pin act_pin);
	void release(const pin act_pin);
	bool is_reserved(const pin act_pin) const;

protected:
	static std::vector<pin> reserved_pins_;							// all the pins are reserved here by their number
};