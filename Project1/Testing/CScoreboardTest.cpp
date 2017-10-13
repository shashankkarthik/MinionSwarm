#include "stdafx.h"
#include "CppUnitTest.h"

#include "Scoreboard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreboardTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestScoreMapInit)
		{
			CScoreboard scoreboard;

			map<string, int> scoreMap = scoreboard.GetScoreMap();
			Assert::AreEqual(0, scoreMap["Juicer"], 0);
			Assert::AreEqual(0, scoreMap["Pokeeball"], 0);
			Assert::AreEqual(0, scoreMap["Arya"], 0);
		}

		TEST_METHOD(TestScoreMapUpdate)
		{
			CScoreboard scoreboard;

			

			map<string, int> testMap;
			testMap["Juicer"] = 1;
			testMap["Pokeeball"] = 2;
			testMap["Arya"] = 3;

			scoreboard.SetScoreMap(testMap);
			map<string, int> scoreMap = scoreboard.GetScoreMap();
			Assert::AreEqual(1, scoreMap["Juicer"], 0);
			Assert::AreEqual(2, scoreMap["Pokeeball"], 0);
			Assert::AreEqual(3, scoreMap["Arya"], 0);


		}

	};
}