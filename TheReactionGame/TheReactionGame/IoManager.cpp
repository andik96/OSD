
/********************************
#   THE REACTION GAME           #
#   IoManager.cpp               #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/02         #
#   Version: 2018/05/20 - V2.0  #
********************************/


// ===============================================================
// INCLUDES

#include "IoManager.hpp"


// #################################### SECTION BREAK ####################################


Io_manager::Io_manager()
{
}

Io_manager::Io_manager(Io_manager && other) noexcept
{
}

Io_manager & Io_manager::operator = (Io_manager && rhs) noexcept
{
	// TODO: hier Rückgabeanweisung eingeben
}

Io_manager::~Io_manager()								// here all the reserved pins will be released again
{
	for (pin act_pin : reserved_pins_)
	{
		this->release(this->reserved_pins_[act_pin]);
	}
}



// #################################### SECTION BREAK ####################################


// Wiringpi 0-16 && 21-31 = 28 Pins

void Io_manager::reserve(pin pin)
{
	/*if(! element pin found)*/
	this->reserved_pins_.push_back;
}

void Io_manager::release(pin pin)
{
	this->reserved_pins_.pop_back(/*element pin found at place ...*/);
}
