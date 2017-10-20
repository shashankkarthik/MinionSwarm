#include "stdafx.h"
#include "CppUnitTest.h"

#include "Game.h"
#include "Gru.h"
#include "Minion.h"
#include "MinionJerry.h"
#include <string>

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CGameTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCGameConstruct)
		{
			CGame game;
		}

		TEST_METHOD(TestCGameGetTime)
		{
			CGame game;
			wstring time = game.GetTime();
			wstring expectedTime = L"0:00";
			Assert::AreEqual(expectedTime, time);

			game.SetTime(11.0);
			wstring time1 = game.GetTime();
			wstring expectedTime1 = L"0:11";
			Assert::AreEqual(expectedTime1, time1);

			game.SetTime(60.0);
			wstring time2 = game.GetTime();
			wstring expectedTime2 = L"1:00";
			Assert::AreEqual(expectedTime2, time2);

			game.SetTime(83.0);
			wstring time3 = game.GetTime();
			wstring expectedTime3 = L"1:23";
			Assert::AreEqual(expectedTime3, time3);
			
			game.SetTime(600.0);
			wstring time4 = game.GetTime();
			wstring expectedTime4 = L"10:00";
			Assert::AreEqual(expectedTime4, time4);

			game.SetTime(0.0);
			wstring time5 = game.GetTime();
			wstring expectedTime5 = L"0:00";
			Assert::AreEqual(expectedTime5, time5);
		}

		TEST_METHOD(TestCGameAdd)
		{
			CGame game;

			Assert::AreEqual(0, game.GetSizemGameTiles());

			std::shared_ptr<CGru> gru;
			game.Add(gru);

			Assert::AreEqual(1, game.GetSizemGameTiles());

		}

		TEST_METHOD(TestCGameSpawnMinion)
		{
			CGame game;
			Assert::AreEqual(0, game.GetSizemGameTiles());

			game.SpawnRandomMinion();
			Assert::AreEqual(1, game.GetSizemGameTiles());

			game.SpawnRandomMinion();
			Assert::AreEqual(2, game.GetSizemGameTiles());

			game.Delete();
			Assert::AreEqual(0, game.GetSizemGameTiles());

			game.SpawnRandomMinion();
			Assert::AreEqual(1, game.GetSizemGameTiles());
		}

		TEST_METHOD(TestCGameDelete)
		{
			CGame game;
			Assert::AreEqual(0, game.GetSizemGameTiles());

			std::shared_ptr<CGru> gru;
			game.Add(gru);

			Assert::AreEqual(1, game.GetSizemGameTiles());
			game.Delete();
			Assert::AreEqual(0, game.GetSizemGameTiles());
		}
		
		TEST_METHOD(TestCGameDeleteItem)
		{
			CGame game;
			Assert::AreEqual(0, game.GetSizemGameTiles());

			std::shared_ptr<CGru> gru;
			game.Add(gru);
			std::shared_ptr<CGru> gru1;
			game.Add(gru1);
			std::shared_ptr<CMinionJerry> jerry;
			game.Add(jerry);

			Assert::AreEqual(3, game.GetSizemGameTiles());
			game.DeleteItem(gru);
			Assert::AreEqual(2, game.GetSizemGameTiles());
			game.DeleteItem(gru1);
			Assert::AreEqual(1, game.GetSizemGameTiles());
			game.DeleteItem(jerry);
			Assert::AreEqual(0, game.GetSizemGameTiles());
		}

		TEST_METHOD(TestCGameUpdate)
		{
			CGame game;
			wstring expectedTime = L"0:00";
			Assert::AreEqual(expectedTime, game.GetTime());

			game.Update(11.5);
			wstring expectedTime1 = L"0:11";
			Assert::AreEqual(expectedTime1, game.GetTime());

			game.Update(33.5);
			wstring expectedTime2 = L"0:45";
			Assert::AreEqual(expectedTime2, game.GetTime());
		}
	};
}