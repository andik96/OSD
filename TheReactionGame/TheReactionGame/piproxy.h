
/********************************
#   THE REACTION GAME           #
#   piproxy.h                   #
#                               #
#   Editors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/14/05         #
#   Version: 2018/20/05 - V1.1  #
********************************/

#pragma once


#if _WIN32 || _WIN64
	#include "../ReactionGameLib/winpi.h"
#else
	#include "wiringPi.h"
#endif