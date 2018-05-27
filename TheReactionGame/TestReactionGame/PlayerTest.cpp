
/********************************
#   THE REACTION GAME           #
#   PlayerTest.cpp              #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/23         #
#   Version: 2018/05/27 - V1.2  #
********************************/


// ===============================================================
// INCLUDES

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheReactionGame/Player.hpp"


// ===============================================================
// NAMESPACES

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// #################################### SECTION BREAK ####################################


// ===============================================================
// REACTION GAME TESTS

namespace test_reaction_game
{		
	TEST_CLASS(player_test)
	{
	public:
		
		TEST_METHOD(test_construction)
		{
			Player p{ 3,5,"AndiK",0 };

			Assert::AreEqual(3, static_cast<int>(p.read_button_pin()));
			Assert::AreEqual(5, static_cast<int>(p.read_led_pin()));
			Assert::AreEqual("AndiK", p.read_name().c_str(), "Names are different.");
			Assert::AreEqual(0, static_cast<int>(p.read_wins()) );
		}

	};
}