
/*********************************
#   THE REACTION GAME            #
#   IDigitalOutput.h             #
#                                #
#   Author:                      #
#       KEMPERLE Andreas         #
#       WINKLER  Andreas         #
#                                #
#   created: 2018/04/02          #
#   Version: 2018/05/27 - V3.1   #
*********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "IoManager.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// INTERFACE

class IDigital_output
{
public:
	virtual void write(bool digital_value) = 0;
	virtual bool read(void) const = 0;
	virtual pin get_pin(void) const = 0;

	virtual ~IDigital_output() = 0;
};