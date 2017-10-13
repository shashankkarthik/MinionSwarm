#include "stdafx.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// image filename 
const std::wstring VillainAryaImageName = L"images/arya.png";

namespace Testing
{
	TEST_CLASS(CItemTest)
	{
	public:

		/** Mock class for testing CItem */
		class CItemMock : public CItem
		{
		public:
			/** Constructor
			* \param aquarium The aquarium this is a member of */
			CItemMock(CGame *game) :
				CItem(game, VillainAryaImageName) {}

			/** Draw the item
			* \param graphics The graphics context to draw on */
			virtual void Draw(Gdiplus::Graphics *graphics) {}
		};

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCItemConstruct)
		{
			CGame game;
			CItemMock item(&game);
		}

		TEST_METHOD(TestCItemGettersSetters)
		{
			CGame game;
			CItemMock item(&game);

			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			item.SetLocation(15.7, 25.5);
			Assert::AreEqual(15.7, item.GetX(), 0.0001);
			Assert::AreEqual(25.5, item.GetY(), 0.0001);

			item.SetLocation(-10.2, -50.5);
			Assert::AreEqual(-10.2, item.GetX(), 0.0001);
			Assert::AreEqual(-50.5, item.GetY(), 0.0001);
		}

		TEST_METHOD(TestCItemHitTest)
		{
			CGame game;
			CItemMock item(&game);

			Assert::IsTrue(item.HitTest(0, 0));

			item.SetLocation(10, 10);

			Assert::IsTrue(item.HitTest(10, 10));
		}
	};
}