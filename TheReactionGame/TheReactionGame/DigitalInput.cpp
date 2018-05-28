
/********************************
#   THE REACTION GAME           #
#   DigitalInput.cpp            #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/23         #
#   Version: 2018/05/28 - V1.4  #
********************************/


// ===============================================================
// INCLUDES

#include "DigitalInput.hpp"
#include "piproxy.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// DECLARE DIGITAL INPUT CLASS (INITIALISER)

Digital_input::Digital_input(Io_manager& my_io_manager, const pin pin_number, const Resistor resistor_type) : 
	my_io_manager_{ my_io_manager }, pin_number_{ pin_number }, resistor_type_{ resistor_type }
{
	my_io_manager_.reserve(this->pin_number_);
	pinMode(pin_number_, INPUT);
}


// ===============================================================
// READ INPUT VALUE

bool Digital_input::read() const
{
	return digitalRead(this->pin_number_);
}

// ===============================================================
// SELECT PULLUPDOWN RESISTOR

void Digital_input::set_resistor(const Resistor resistor_type)
{
	pullUpDnControl(this->pin_number_, static_cast<int>(resistor_type));
	resistor_type_ = resistor_type;
}

// ===============================================================
// ASK FOR PIN NUMBER

pin Digital_input::get_pin(void) const
{
	return this->pin_number_;
}

// ===============================================================
// ASK FOR INPUT RESISTOR

Resistor Digital_input::get_resistor_type(void) const
{
	return this->resistor_type_;
}


// ===============================================================
// DESTRUCTOR

Digital_input::~Digital_input()
{
	pullUpDnControl(this->pin_number_, static_cast<int>(Resistor::no_resistor));		// reset pullup/down resistor

	my_io_manager_.release(this->pin_number_);
}
