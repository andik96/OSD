
/*********************************
#   THE REACTION GAME            #
#   IDigitalInput.hpp            #
#                                #
#   Author:                      #
#       KEMPERLE Andreas         #
#       WINKLER  Andreas         #
#                                #
#   created: 2018/04/02          #
#   Version: 2018/05/28 - V2.1   #
*********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "IoManager.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// INTERFACE

class IDigital_input
{
public:
	virtual bool read() const = 0;
	virtual void set_resistor(Resistor resistor_type) = 0;
	virtual pin get_pin(void) const = 0;
	virtual Resistor get_resistor_type(void) const = 0;

	virtual ~IDigital_input() = 0;
};