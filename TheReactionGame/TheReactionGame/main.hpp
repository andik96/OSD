
/********************************
#   THE REACTION GAME           #
#   main.hpp                    #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/14/05         #
#   Version: 2018/20/05 - V1.1  #
********************************/

#pragma once


// ===============================================================
// TYPEDEFS

using pin = unsigned short;

// ===============================================================
// CONSTANT EXPRESSIONS

constexpr unsigned short max_game_rounds = 30;
constexpr unsigned short max_time_inactive = 3000;
constexpr unsigned short led_winner_time = 3000;

// ===============================================================
// ENUMS

enum Winner { p1 = 1, p2, tie, timeout }; // for console output, it is important, that p1 = 1 and p2 = 2