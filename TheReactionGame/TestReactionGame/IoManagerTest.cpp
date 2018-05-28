
/********************************
#   THE REACTION GAME           #
#   IoManagerTest.cpp           #
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
#include "../TheReactionGame/IoManager.hpp"


// ===============================================================
// NAMESPACES

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// #################################### SECTION BREAK ####################################


// ===============================================================
// REACTION GAME TESTS

namespace test_reaction_game
{		
	TEST_CLASS(Io_manager_test)
	{
	public:
		TEST_METHOD(test_construction1)
		{
			Io_manager my_manager{};

			Assert::IsFalse(my_manager.is_reserved(0));
			
			my_manager.reserve(0);
			Assert::IsTrue(my_manager.is_reserved(0));

			my_manager.release(0);
			Assert::IsFalse(my_manager.is_reserved(0));

			my_manager.reserve(0);
			Assert::IsTrue(my_manager.is_reserved(0));
		}

		TEST_METHOD(test_construction2)
		{
			Io_manager my_manager{};

			//my_manager.reserve(1);
			//Assert::AreEqual(1,static_cast<int>(my_manager.is_reserved(static_cast<pin>(1) ) ) );

			/*my_manager.release(5);
			Assert::IsFalse(my_manager.is_reserved(5));

			my_manager.reserve(5);
			Assert::IsTrue(my_manager.is_reserved(5));*/
		}

	};
}