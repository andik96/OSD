
/********************************
#   THE REACTION GAME           #
#   IncludeJsonData.cpp         #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/10         #
#   Version: 2018/05/20 - V1.2  #
********************************/


// ===============================================================
// INCLUDES

#include "IncludeJsonData.hpp"
#include <fstream>
#include <iostream>


// #################################### SECTION BREAK ####################################


// ===============================================================
// GET PINS FUNCTION (to read from json file)

nlohmann::json get_pins()
{
	nlohmann::json pins;
	std::ifstream pins_file("pins.json");
	pins_file >> pins;

	return pins;
}