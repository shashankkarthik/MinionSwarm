#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Item.h"
#include "Gru.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGruTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCAquariumConstruct)
		{
			CGame game;
		}

		TEST_METHOD(TestGruInit)
		{
			CGame game;
			CGru gru(&game);
		}
		TEST_METHOD(TestGruSetLocation)
		{
			CGame game;
			CGru gru(&game);

			Assert::IsTrue(gru.GetX() == 0);
			Assert::IsTrue(gru.GetY() == 0);
			gru.SetLocation(200, -401);
			Assert::IsTrue(gru.GetX() == 200);
			Assert::IsTrue(gru.GetY() == -401);
			


		}
		TEST_METHOD(TestGruKill)
		{
			CGame game;
			CGru gru(&game);

			Assert::IsTrue(gru.IsAlive() == true);
			gru.Kill();
			Assert::IsTrue(gru.IsAlive() == false);



		}
		TEST_METHOD(TestGruHitTest)
		{
			// Create a fish to test
			CGame game;
			CGru gru(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			gru.SetLocation(100, 200);

			// Center of the fish should be a true
			Assert::IsTrue(gru.HitTest(100, 200));

			// Left of the Gru
			Assert::IsFalse(gru.HitTest(10, 200));

			// Right of the Gru
			Assert::IsFalse(gru.HitTest(200, 200));

			// Above the Gru
			Assert::IsFalse(gru.HitTest(100, 0));

			// Below the Gru
			Assert::IsFalse(gru.HitTest(100, 300));

			// Of Gru transparent pixel
			Assert::IsFalse(gru.HitTest(100 - 125 / 2 + 17, 200 - 117 / 2 + 16));
		}


		
	};
}