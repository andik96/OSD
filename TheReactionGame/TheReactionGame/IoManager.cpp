
/********************************
#   THE REACTION GAME           #
#   IoManager.cpp               #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/02         #
#   Version: 2018/05/24 - V2.1  #
********************************/


// ===============================================================
// INCLUDES

#include "IoManager.hpp"


// #################################### SECTION BREAK ####################################


Io_manager::Io_manager()
{
}

//Io_manager::Io_manager(Io_manager && other) noexcept;
//{
//}
//
//Io_manager & Io_manager::operator = (Io_manager && rhs) noexcept;
//{
//	// TODO: implementation of move operator
//}

Io_manager::~Io_manager()								// here all the reserved pins will be released again
{
	for (pin act_pin : reserved_pins_)
	{
		this->release(this->reserved_pins_[act_pin]);
	}
}



// #################################### SECTION BREAK ####################################


// Wiringpi 0-16 && 21-31 = 28 Pins

void Io_manager::reserve(pin act_pin)
{
	if(!is_reserved(act_pin))
		this->reserved_pins_.push_back;
	else
		throw std::runtime_error("Pin already reserved!");
}

void Io_manager::release(pin act_pin)
{
	if (is_reserved(act_pin))
		this->reserved_pins_.erase(std::find(this->reserved_pins_.begin(), this->reserved_pins_.end(), act_pin));
	else
		throw std::runtime_error("Nothing to release!");
}

bool Io_manager::is_reserved(pin act_pin)
{
	return std::find(this->reserved_pins_.begin(), this->reserved_pins_.end(), act_pin) != this->reserved_pins_.end();
}
