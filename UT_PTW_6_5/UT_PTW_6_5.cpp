#include "pch.h"
#include "CppUnitTest.h"
#include "../PTW_6_5/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UTPTW65
{
	TEST_CLASS(UTPTW65)
	{
	public:
		
		TEST_METHOD(Sort_ValidStack_SortedStack)
		{
			// Arrange
			Elem *top = NULL, *sorted = NULL;

			Info expected = '1';

			Push(top, expected);
			Push(top, expected - 1);

			// Act
			Sort(top, sorted);

			Info actual = sorted->info;

			while (top)
			{
				Pop(top);
			}

			while (sorted)
			{
				Pop(sorted);
			}

			// Assert
			Assert::AreEqual(expected, actual);
		}
	};
}
