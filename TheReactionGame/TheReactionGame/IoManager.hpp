
/********************************
#   THE REACTION GAME           #
#   IoManager.h                 #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/02         #
#   Version: 2018/05/02 - V1.0  #
********************************/

#pragma once
#include "json.hpp"


// #################################### SECTION BREAK ####################################


// ===============================================================
// DECLARE CLASS FOR MANAGING IO-PINS

class Io_manager
{
public:
	Io_manager();
	Io_manager(const Io_manager & other);
	Io_manager(Io_manager && other) noexcept;	// move constructor
	Io_manager& operator = (const Io_manager& rhs);
	Io_manager& operator = (Io_manager&& rhs) noexcept;
	~Io_manager();

	void reserve(nlohmann::json pins_config);
	//void release(int pin);
};