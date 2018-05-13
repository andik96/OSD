
/********************************
#   THE REACTION GAME           #
#   IncludeJsonData.cpp         #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/10         #
#   Version: 2018/05/13 - V1.1  #
********************************/


// ===============================================================
// INCLUDES

#include "IncludeJsonData.hpp"
#include <fstream>


// #################################### SECTION BREAK ####################################


// ===============================================================
// GET PINS FUNCTION (to read from json file)

nlohmann::json get_pins()
{
	nlohmann::json pins;
	std::ifstream pins_file("pins.json", std::ifstream::binary);
	pins_file >> pins;

	int p1_led = pins["p1_led"].get<int>();		// has to be put into main.cpp

	return pins;
}