
/********************************
#   THE REACTION GAME           #
#   DigitalInput.cpp            #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/23         #
#   Version: 2018/05/24 - V1.1  #
********************************/


// ===============================================================
// INCLUDES

#include "DigitalInput.hpp"
#include "piproxy.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// (DEFAULT) CONSTRUCTOR

Digital_input::Digital_input()
{
	pinMode(this->pin_number_, INPUT);
}

// ===============================================================
// DECLARE DIGITAL INPUT CLASS (INITIALISER)

Digital_input::Digital_input(pin pin_number, Resistor resistor_type)
{
}

// ===============================================================
// READ INPUT VALUE

bool Digital_input::read() const
{
	return digitalRead(this->pin_number_);
}

// ===============================================================
// SELECT PULLUPDOWN RESISTOR

void Digital_input::set_resistor(Resistor resistor_type)
{
	pullUpDnControl(this->pin_number_, static_cast<int>(resistor_type));
}

// ===============================================================
// ASK FOR PIN NUMBER

pin Digital_input::get_pin(void) const
{
	return this->pin_number_;
}


// ===============================================================
// DESTRUCTOR

Digital_input::~Digital_input()
{
}
