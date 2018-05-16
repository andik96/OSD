#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TheReactionGame/Player.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestReactionGame
{		
	TEST_CLASS(Player_test)
	{
	public:
		
		TEST_METHOD(Test_construction)
		{
			Player p{ 3,5,"AndiK",0 };

			Assert::AreEqual(3, static_cast<int>(p.read_button_pin()));
			Assert::AreEqual(5, static_cast<int>(p.read_led_pin()));
			Assert::AreEqual("AndiK", p.read_name().c_str(), "Names are different.");
			//Assert::AreEqual("0", static_cast<std::string>(p.read_wins()), "wins are different");
		}

	};
}