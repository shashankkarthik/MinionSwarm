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
			gru.KillGru();
			Assert::IsTrue(gru.IsAlive() == false);



		}


		
	};
}