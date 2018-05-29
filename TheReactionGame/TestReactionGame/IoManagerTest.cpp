
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
			my_manager.release(0);
		}

		TEST_METHOD(test_construction2)
		{
			Io_manager my_manager{};

			try
			{
				my_manager.reserve(5);
				my_manager.reserve(3);
				my_manager.reserve(27);
				my_manager.reserve(20);				// <- this one will throw an exception, pin does not exist
			}
			catch(...)
			{ }

			Assert::IsTrue(static_cast<int>(my_manager.is_reserved(5)));
			Assert::IsTrue(static_cast<int>(my_manager.is_reserved(3)));
			Assert::IsTrue(static_cast<int>(my_manager.is_reserved(27)));
			Assert::IsFalse(static_cast<int>(my_manager.is_reserved(20)));

			// test, if uninitialised pin is reserved
			Assert::IsFalse(static_cast<int>(my_manager.is_reserved(0)));
			// test, if non-existing pin is reserved
			Assert::IsFalse(static_cast<int>(my_manager.is_reserved(40)));

		}

	};
}