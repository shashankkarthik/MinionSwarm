#include "stdafx.h"
#include "CppUnitTest.h"

#include "ChildView.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CChildViewTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestChildViewConstuctor)
		{
			CChildView childView;
		}

	};
}