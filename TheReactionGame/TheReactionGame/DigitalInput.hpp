
/********************************
#   THE REACTION GAME           #
#   DigitalInput.hpp            #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/23         #
#   Version: 2018/05/23 - V1.0  #
********************************/

#pragma once


// ===============================================================
// INCLUDES

#include "IDigitalInput.hpp"
#include "IoManager.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// DIGITAL INPUT IMPLEMENTATION

class Digital_input : public IDigital_input
{
public:
	Digital_input();
	Digital_input(pin pin_number, Resistor resistor_type);

	// --------- --------- --------- ---------
	bool read() const override;
	// ---------
	void set_resistor(Resistor resistor_type) override;
	// --------- --------- --------- ---------

private:
	pin pin_number_;
	Resistor resistor_type_;
	// Io_manager(pin_number_);
};

