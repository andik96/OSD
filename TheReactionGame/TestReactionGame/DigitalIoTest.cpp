
/********************************
#   THE REACTION GAME           #
#   DigitalIoTest.cpp           #
#                               #
#   Authors:                    #
#       KEMPERLE Andreas        #
#       WINKLER  Andreas        #
#                               #
#   created: 2018/05/27         #
#   Version: 2018/05/27 - V1.0  #
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

namespace TestReactionGame
{
	TEST_CLASS(Digital_input_test)
	{
	public:

		TEST_METHOD(Test_construction)
		{
			Io_manager my_io_manager;

			Digital_input test_input1{ my_io_manager, 10, Resistor::pulldown };
			Digital_input test_input2{ my_io_manager, 10, Resistor::pullup };
			Digital_input test_input3{ my_io_manager,30,Resistor::no_resistor };

			Assert::AreEqual(10, static_cast<int>(test_input1.get_pin()));
			Assert::AreEqual(10, static_cast<int>(test_input2.get_pin()));
			Assert::AreEqual(30, static_cast<int>(test_input3.get_pin()));
		}

	};

	TEST_CLASS(Digital_output_test)
	{
	public:

		TEST_METHOD(Test_construction)
		{
			/*
			Io_manager my_io_manager;

			Digital_input test_input1{ my_io_manager, 10, Resistor::pulldown };
			Digital_input test_input2{ my_io_manager, 10, Resistor::pullup };
			Digital_input test_input3{ my_io_manager,30,Resistor::no_resistor };

			Assert::AreEqual(10, static_cast<int>(test_input1.get_pin()));
			Assert::AreEqual(10, static_cast<int>(test_input2.get_pin()));
			Assert::AreEqual(30, static_cast<int>(test_input3.get_pin()));
			*/
		}

	};
}