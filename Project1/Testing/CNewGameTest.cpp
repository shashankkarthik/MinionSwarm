#include "stdafx.h"
#include "CppUnitTest.h"

#include "NewGame.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CNewGameTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCNewGameConstructor)
		{
			CNewGame newGame;
		}

		TEST_METHOD(TestCNewGameHitTest)
		{
			CNewGame newGame;
			//Top left corner tests
			Assert::IsTrue(newGame.HitTest(0,0));
			Assert::IsFalse(newGame.HitTest(-1, 0));
			Assert::IsFalse(newGame.HitTest(0, -1));
			//Top right corner tests
			Assert::IsTrue(newGame.HitTest(199, 0));
			Assert::IsFalse(newGame.HitTest(200, 0));
			Assert::IsFalse(newGame.HitTest(199, -1));
			//Bottom left corner tests
			Assert::IsTrue(newGame.HitTest(0, 111));
			Assert::IsFalse(newGame.HitTest(-1, 111));
			Assert::IsFalse(newGame.HitTest(0, 112));
			//Bottom right corner tests
			Assert::IsTrue(newGame.HitTest(199, 111));
			Assert::IsFalse(newGame.HitTest(200, 111));
			Assert::IsFalse(newGame.HitTest(199, 112));
			//Middle test
			Assert::IsTrue(newGame.HitTest(100, 56));
		
		}

	};
}