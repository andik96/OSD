
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
	TEST_CLASS(Digital_input_test)
	{
	public:
		
		TEST_METHOD(test_construction)
		{
			Io_manager my_io_manager;

			Digital_input test_input1{ my_io_manager, 10, Resistor::pulldown };
			Digital_input test_input2{ my_io_manager,24, Resistor::no_resistor };
			{
				Digital_input test_input3{ my_io_manager, 0, Resistor::pulldown };		// create local object to test if pin is released again
			}
			Digital_input test_input3{ my_io_manager, 0, Resistor::pullup };

			// Digital_input test_input4{ my_io_manager, 10, Resistor::pullup }; 		// <-- will throw exception (pin already reserved)
			// Digital_input test_input5{ my_io_manager, 19, Resistor::no_resistor };	// <-- will throw exception (pin does not exist)


			Assert::AreEqual(10, static_cast<int>(test_input1.get_pin()));
			Assert::AreEqual(static_cast<int>(Resistor::pulldown), static_cast<int>(test_input1.get_resistor_type()));
			Assert::AreEqual(24, static_cast<int>(test_input2.get_pin()));
			Assert::AreEqual(static_cast<int>(Resistor::no_resistor), static_cast<int>(test_input2.get_resistor_type()));
			Assert::AreEqual(0, static_cast<int>(test_input3.get_pin()));
			Assert::AreEqual(static_cast<int>(Resistor::pullup), static_cast<int>(test_input2.get_resistor_type()));
		}

	};

	TEST_CLASS(Digital_output_test)
	{
	public:

		TEST_METHOD(test_construction)
		{
			Io_manager my_io_manager;

			Digital_output test_output1{ my_io_manager, 10 };
			Digital_output test_output2{ my_io_manager, 24 };
			{
				Digital_output test_output3{ my_io_manager, 0 };			// create local object to test if pin is released again
			}
			Digital_output test_output3{ my_io_manager, 0 };

			// Digital_output test_output4{ my_io_manager, 10 };		// <-- will throw exception (pin already reserved)
			// Digital_output test_output5{ my_io_manager, 19 };		// <-- will throw exception (pin does not exist)


			Assert::AreEqual(10, static_cast<int>(test_output1.get_pin()));
			Assert::AreEqual(24, static_cast<int>(test_output2.get_pin()));
			Assert::AreEqual(0, static_cast<int>(test_output3.get_pin()));
		}

	};
}