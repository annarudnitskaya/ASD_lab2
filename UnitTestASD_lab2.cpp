#include "pch.h"
#include "CppUnitTest.h"
#include "../ASD_lab2/ASD_lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
const int test_size_array = 10;

namespace UnitTestASDlab2
{
	TEST_CLASS(UnitTestASDlab2)
	{
	public:
		
		TEST_METHOD(TestQuickSort)
		{
			int* Test_array = new int[test_size_array];
			for (int i = 0; i < test_size_array; i++) Test_array[i] = 10 - i;
			int first = 0; int last = test_size_array - 1;
			QuickSort(Test_array, first, last);
			for (int i = 0; i < test_size_array - 1; i++) {
				Assert::IsTrue(Test_array[i] < Test_array[i + 1]);
			}
			delete[]Test_array;
		}

		TEST_METHOD(TestInsertionSort)
		{
			int* Test_array = new int[test_size_array];
			for (int i = 0; i < test_size_array; i++) Test_array[i] = 10 - i;
			InsertionSort(Test_array, test_size_array);
			for (int i = 0; i < test_size_array - 1; i++) {
				Assert::IsTrue(Test_array[i] < Test_array[i + 1]);
			}
			delete[]Test_array;
		}

		TEST_METHOD(TestBogoSort)
		{
			int* Test_array = new int[test_size_array];
			for (int i = 0; i < test_size_array; i++) Test_array[i] = 10 - i;
			BogoSort(Test_array, test_size_array);
			for (int i = 0; i < test_size_array - 1; i++) {
				Assert::IsTrue(Test_array[i] < Test_array[i + 1]);
			}
			delete[]Test_array;
		}
		
		TEST_METHOD(TestCountingSort)
		{
			char* test_array = new char[4];
			test_array[0] = 'd';
			test_array[1] = 'c';
			test_array[2] = 'b';
			test_array[3] = 'a';

			CountingSort(test_array, 4);

			Assert::IsTrue(test_array[0] == 'a');
			Assert::IsTrue(test_array[1] == 'b');
			Assert::IsTrue(test_array[2] == 'c');
			Assert::IsTrue(test_array[3] == 'd');

			delete[]test_array;
		}

		TEST_METHOD(TestBinarySearch)
		{
			const int test_size = 10;
			int* test_array = new int[test_size];
			for (int i = 0; i < test_size; i++)
			{
				test_array[i] = 20 - i;
			}
			try {
				BinarySearch(test_array, test_size, 3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("The array is not sorted in ascending order", error.what());
			}
			InsertionSort(test_array, test_size);
			try {
				BinarySearch(test_array, test_size, 3);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is not element in array", error.what());
			}

			try {
				BinarySearch(test_array, test_size, 13);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is not element in array", error.what());
			}
			Assert::IsTrue(BinarySearch(test_array, test_size, 13) == 2);
			delete[]test_array;
		}

	};
}
