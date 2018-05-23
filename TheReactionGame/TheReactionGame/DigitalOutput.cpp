
/********************************
#   THE REACTION GAME           #
#   DigitalOutput.cpp           #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/23         #
#   Version: 2018/05/23 - V1.0  #
********************************/


// ===============================================================
// INCLUDES

#include "DigitalOutput.hpp"
#include "piproxy.h"


// #################################### SECTION BREAK ####################################


// ===============================================================
// (DEFAULT) CONSTRUCTOR

Digital_output::Digital_output()
{
	pinMode(this->pin_number_, OUTPUT);
}

// ===============================================================
// DECLARE DIGITAL OUTPUT CLASS (INITIALISER)

Digital_output::Digital_output(pin pin_number) : pin_number_{pin_number}
{
}


// ===============================================================
// WRITE TO OUTPUT

void Digital_output::write(bool value)
{
	digitalWrite(this->pin_number_, value);
}

// ===============================================================
// READ OUTPUT STATE

bool Digital_output::read(void) const
{
	return digitalRead(this->pin_number_);
}


// ===============================================================
// DESTRUCTOR

Digital_output::~Digital_output()
{
}
