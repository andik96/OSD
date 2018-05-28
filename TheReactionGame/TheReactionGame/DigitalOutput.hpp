
/********************************
#   THE REACTION GAME           #
#   DigitalOutput.hpp           #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/23         #
#   Version: 2018/05/27 - V2.1  #
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
	Digital_output(Io_manager& my_io_manager, pin pin_number);
	~Digital_output();

	// --------- --------- --------- ---------
	void write(bool digital_value) override;
	// ---------
	bool read(void) const override;
	// --------- --------- --------- ---------
	pin get_pin(void) const override;
	// --------- --------- --------- ---------

private:
	Io_manager & my_io_manager_;
	pin pin_number_;
};

