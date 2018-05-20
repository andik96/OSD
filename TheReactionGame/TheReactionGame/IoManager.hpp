
/********************************
#   THE REACTION GAME           #
#   IoManager.hpp               #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/02         #
#   Version: 2018/05/20 - V1.1  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "json.hpp"
#include "main.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// DECLARE CLASS FOR MANAGING IO-PINS

class Io_manager
{
public:
	Io_manager();													// here the pin will be reserved
	Io_manager(const Io_manager & other) = delete;					// you are not allowed to copy any pin!
	Io_manager(Io_manager && other) noexcept;						// move constructor will be needed for transfering a pin
	Io_manager& operator = (const Io_manager& rhs) = delete;		// you are not allowed to copy any pin!
	Io_manager& operator = (Io_manager&& rhs) noexcept;				// a pin may be released and taken by another function
	~Io_manager();													// here the pin will be released again

	void reserve(nlohmann::json pins_config);
	void release(pin pin);

protected:
	// reserved_pins;				object from ReservedPins.cpp
};