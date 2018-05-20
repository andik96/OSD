
/*********************************
#   THE REACTION GAME            #
#   IDigitalInput.hpp            #
#                                #
#   Author:                      #
#       KEMPERLE Andreas         #
#       WINKLER  Andreas         #
#                                #
#   created: 2018/04/02          #
#   Version: 2018/05/20 - V1.2   #
*********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "IoEnums.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// INTERFACE

class IDigitalInput
{
public:
	virtual bool read() const = 0;
	virtual void set_resistor(Resistor resistor_type) = 0;

	virtual ~IDigitalInput() = 0;
};