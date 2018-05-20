
/********************************
#   THE REACTION GAME           #
#   IoManager.cpp               #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/02         #
#   Version: 2018/05/20 - V1.1  #
********************************/


// ===============================================================
// INCLUDES

#include "IoManager.hpp"
#include "IncludeJsonData.hpp"


// #################################### SECTION BREAK ####################################


Io_manager::Io_manager()
{
}

Io_manager::Io_manager(Io_manager && other) noexcept
{
}

Io_manager & Io_manager::operator = (Io_manager && rhs) noexcept
{
	// TODO: hier Rückgabeanweisung eingeben
}

Io_manager::~Io_manager()								// here all the reserved pins will be released again
{
}



// #################################### SECTION BREAK ####################################


// Wiringpi 0-16 && 21-31 = 28 Pins

void Io_manager::reserve(nlohmann::json pins_config)
{
}

void Io_manager::release(pin pin)
{
}
