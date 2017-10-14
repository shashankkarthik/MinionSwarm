#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Item.h"
#include "Gru.h"
#include "ChildView.h"
#include "Villain.h"
#include "VillainArya.h"
#include "VillainJuicer.h"
#include "VillainPokeball.h"
#include "Minion.h"
#include "MinionJerry.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace Testing
{
	TEST_CLASS(CMinionCChildViewTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestMinionConstructor)
		{
			CGame game;
			CMinionJerry jerry(&game);
		}

		TEST_METHOD(TestMinionLocaton)
		{
			CGame game;
			CMinionJerry jerry(&game);

			Assert::IsTrue(jerry.GetX() == 0);
			Assert::IsTrue(jerry.GetY() == 0);
			jerry.SetLocation(200, -401);
			Assert::IsTrue(jerry.GetX() == 200);
			Assert::IsTrue(jerry.GetY() == -401);

			Assert::IsTrue(jerry.GetPoints() == 1);
		}

		TEST_METHOD(TestChildViewConst)
		{
			CGame game;
			CChildView childView;
			Assert::IsTrue(game.GetSizemGameTiles() == 4);
		}
	};
}