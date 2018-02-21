#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

__declspec(dllimport) int MulMe(int, int);
__declspec(dllimport) int MulMePointers(int*, int*);
__declspec(dllimport) int MulMeReference(int&, int&);
int AddMe(int, int);

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMulMe)
		{
			int answer = MulMe(5, 8);
			Assert::AreEqual(40, answer);
		}
		TEST_METHOD(TestMulMePointers)
		{
			int x = 7, y = 3;
			int answer = MulMePointers(&x, &y);
			Assert::AreEqual(21, answer);
		}
		TEST_METHOD(TestMulMePointersNull)
		{
			int x = 7, y = 3;
			int answer = MulMePointers(NULL, &y);
			Assert::AreEqual(0, answer);
		}
		TEST_METHOD(TestMulMePointersNullSecond)
		{
			int x = 7, y = 3;
			int answer = MulMePointers(NULL, &y);
			Assert::AreEqual(0, answer);
		}
		TEST_METHOD_INITIALIZE(TestAddMeInit) {

		}
		TEST_METHOD(TestAddMe)
		{
			TestAddMeInit();
			int x = 7, y = 3;
			int answer = AddMe(x,y);
			Assert::AreEqual(10, answer);
			TestAddMeCleanup();
		}
		TEST_METHOD_CLEANUP(TestAddMeCleanup)
		{
			
		}
	};
}