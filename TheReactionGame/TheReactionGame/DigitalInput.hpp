
/********************************
#   THE REACTION GAME           #
#   DigitalInput.hpp            #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/23         #
#   Version: 2018/05/27 - V1.1  #
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
	Digital_input(Io_manager& my_io_manager, pin pin_number, Resistor resistor_type);
	~Digital_input();

	// --------- --------- --------- ---------
	bool read() const override;
	// ---------
	void set_resistor(Resistor resistor_type) override;
	// --------- --------- --------- ---------
	pin get_pin(void) const override;
	// --------- --------- --------- ---------
	Resistor get_resistor_type(void) const override;
	// --------- --------- --------- ---------

private:
	Io_manager & my_io_manager_;
	pin pin_number_;
	Resistor resistor_type_;
};

