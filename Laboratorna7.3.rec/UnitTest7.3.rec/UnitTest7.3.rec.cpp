#include "pch.h"
#include "CppUnitTest.h"
#include "../Laboratorna7.3.rec/Laboratorna7.3.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest73rec
{
	TEST_CLASS(UnitTest73rec)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int K = 3;
            const int N = 3;
            int** a = new int* [K];
            for (int i = 0; i < K; i++)
                a[i] = new int[N];

            a[0][0] = 1; a[0][1] = 0; a[0][2] = 3;
            a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
            a[2][0] = 7; a[2][1] = 8; a[2][2] = 0;

            int expectedCount = 1;
            int actualCount = CountColumnsWithoutZeros(a, K, N);
            Assert::AreEqual(expectedCount, actualCount);

            for (int i = 0; i < K; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
