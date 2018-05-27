
/********************************
#   THE REACTION GAME           #
#   DigitalIoTest.cpp           #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/27         #
#   Version: 2018/05/27 - V1.1  #
********************************/


// ===============================================================
// INCLUDES

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheReactionGame/DigitalInput.hpp"
#include "../TheReactionGame/DigitalOutput.hpp"


// ===============================================================
// NAMESPACES

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


// #################################### SECTION BREAK ####################################


// ===============================================================
// REACTION GAME TESTS

namespace test_reaction_game
{
	TEST_CLASS(digital_input_test)
	{
	public:
		
		TEST_METHOD(test_construction)
		{
			Io_manager my_io_manager;

			Digital_input test_input1{ my_io_manager, 10, Resistor::pulldown };
			// Digital_input test_input2{ my_io_manager, 10, Resistor::pulldown };		// <-- will throw exception (pin already reserved)
			// Digital_input test_input3{ my_io_manager, 19, Resistor::pulldown };		// <-- will throw exception (pin does not exist)

			Assert::AreEqual(10, static_cast<int>(test_input1.get_pin()));
		}

	};

	TEST_CLASS(digital_output_test)
	{
	public:

		TEST_METHOD(test_construction)
		{
			Io_manager my_io_manager;

			Digital_output test_output1{ my_io_manager, 10};
			// Digital_output test_output2{ my_io_manager, 10 };		// <-- will throw exception (pin already reserved)
			// Digital_output test_output3{ my_io_manager, 19 };		// <-- will throw exception (pin does not exist)

			Assert::AreEqual(10, static_cast<int>(test_output1.get_pin()));
		}

	};
}