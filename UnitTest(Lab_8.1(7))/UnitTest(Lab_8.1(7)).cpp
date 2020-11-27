#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.1(7)/Lab_8.1(7).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab817
{
	TEST_CLASS(UnitTestLab817)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char lit_r[30] = "SQsdgdgQShhQQQSdhd";
			char para[] = "SQ";
			char para1[] = "QS";
			char zamina[] = "*";

			InsertBefore(lit_r, para, zamina, true);
			InsertBefore(lit_r, para1, zamina, false);
			Delete(lit_r, para);
			Delete(lit_r, para1);

			Assert::AreEqual(lit_r[0], '*');
			Assert::AreEqual(lit_r[1], '*');
			Assert::AreEqual(lit_r[2], '*');
		}
	};
}
