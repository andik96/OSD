
/********************************
#   THE REACTION GAME           #
#   DigitalOutput.cpp           #
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

#include "DigitalOutput.hpp"
#include "piproxy.h"
#include "IoManager.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// DECLARE DIGITAL OUTPUT CLASS (INITIALISER)

Digital_output::Digital_output(Io_manager& my_io_manager, const pin pin_number) : 
	my_io_manager_{ my_io_manager }, pin_number_{ pin_number }
{
	my_io_manager_.reserve(this->pin_number_);
	pinMode(this->pin_number_, OUTPUT);
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
// ASK FOR PIN NUMBER

pin Digital_output::get_pin(void) const
{
	return this->pin_number_;
}


// ===============================================================
// DESTRUCTOR

Digital_output::~Digital_output()
{
	my_io_manager_.release(this->pin_number_);
}
