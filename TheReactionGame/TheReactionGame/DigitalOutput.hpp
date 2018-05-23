
/********************************
#   THE REACTION GAME           #
#   DigitalOutput.hpp           #
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

#include "IDigitalOutput.hpp"
#include "IoManager.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// DIGITAL OUTPUT IMPLEMENTATION

class Digital_output : public IDigital_output
{
public:
	Digital_output();
	Digital_output(pin pin_number);

	// --------- --------- --------- ---------
	void write(bool digital_value) override;
	// ---------
	bool read(void) const override;
	// --------- --------- --------- ---------

private:
	pin pin_number_;
	// Io_manager(pin_number_);
};

