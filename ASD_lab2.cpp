

#include <iostream>
#include <ctime>

using namespace std;

// declaration the constant
const int size = 10;

// quick sort in ascending order
void QuickSort(int* array, int first, int last) {
	int middle;
	int left = first, right = last;
	middle = array[(left + right) / 2]; //  calculate the support element
	do
	{
		while (array[left] < middle) left++;
		while (array[right] > middle) right--;
		if (left <= right) // swap the elements
		{
			int temporary = array[left];
			array[left] = array[right];
			array[right] = temporary;
			left++;
			right--;
		}
	} while (left < right);
	if (first < right) QuickSort(array, first, right); // sort the sub-array
	if (left < last) QuickSort(array, left, last);
}

// insertion sort in ascending order

void InsertionSort(int* array, const int size) {
	int i = 0;
	//int j;
	for (int i = 1; i < size; i++)
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--) {
			int k = array[j];
			array[j] = array[j - 1];
			array[j - 1] = k;
		}

			
}

// check the correct array order for bogo sort
int ArrayCorrect(int* array, int size) {
	while (size-- > 0)
		if (array[size - 1] > array[size])
			return 0;
	return 1;
}

// swap the array random elements for bogo sort
void BogoShuffle(int* array, int size) {
	for (int i = 0; i < size; ++i)
		swap(array[i], array[(rand() % size)]);
}

// bogo sort in ascending order
void BogoSort(int* array, int size) {
	while (!ArrayCorrect(array, size)) // while array is not sorted in ascending order
		BogoShuffle(array, size); // swap random elements
}

// counting sort in lexicographic order
void CountingSort(char* array, int size) {
	char char_array[256] = { 0 }; // 256 is the max different count of char
	for (int i = 0; i < size; ++i) {
		++char_array[array[i]]; // calculate the count of each char
	}

	int order = 0; // go through all char
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < char_array[i]; ++j) {
			array[order++] = i;
		}
	}
}

// binary search the element in array
int BinarySearch(int* array, int size, int looking_for) {
	if (ArrayCorrect(array, size) == 1) { // if array is sorted in ascending order
		int left = 0;
		int right = size - 1;
		bool IsFound = false;
		int middle;

		while ((left <= right) && (IsFound != true)) {
			middle = (left + right) / 2; // calculate the middle index

			if (array[middle] == looking_for) IsFound = true; // if moddle index is looking for element
			if (array[middle] > looking_for) right = middle - 1; // discard the useless part of array
			else left = middle + 1;
		}

		if (IsFound) return middle; // if looking for element is exist
		else
		{
			throw invalid_argument("There is not element in array");
		}
	}
	else throw invalid_argument("The array is not sorted in ascending order");
}

void main() {
	const int size_array = 10;

	cout << "Array - " << size_array << " elements:\n";
	int* QuickTest_array = new int[size_array];
	int first = 0; int last = size_array - 1;
	srand(time(NULL)); // clear the random element 
	for (int i = 0; i < size_array; i++)
	{
		QuickTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << QuickTest_array[i] << ' ';
	}
	cout << "\nSort the array with QuickSort:\n";
	QuickSort(QuickTest_array, first, last);
	for (int i = 0; i < size_array; i++) {
		cout << QuickTest_array[i] << ' ';
	}
	delete[]QuickTest_array;

	cout << "\n\n";

	cout << "Array - " << size_array << " elements:\n";
	int* InsertionTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		InsertionTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << InsertionTest_array[i] << ' ';
	}
	cout << "\nSort the array with InsertionSort:\n";
	InsertionSort(InsertionTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << InsertionTest_array[i] << ' ';
	}
	delete[]InsertionTest_array;

	cout << "\n\n";

	cout << "Array - " << size_array << " elements:\n";
	int* BogoTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		BogoTest_array[i] = rand() % 1000;
	}
	for (int i = 0; i < size_array; i++) {
		cout << BogoTest_array[i] << ' ';
	}
	cout << "\nSort the array with BogoSort:\n";
	BogoSort(BogoTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << BogoTest_array[i] << ' ';
	}
	delete[]BogoTest_array;

	cout << "\n\n";

	cout << "Array - " << size_array << " elements:\n";
	char* CountingTest_array = new char[size_array];
	for (int i = 0; i < size_array; i++)
	{
		CountingTest_array[i] = rand() % 255;
	}
	for (int i = 0; i < size_array; i++) {
		cout << CountingTest_array[i] << ' ';
	}
	cout << "\nSort the array with CountingSort:\n";
	CountingSort(CountingTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << CountingTest_array[i] << ' ';
	}
	delete[]CountingTest_array;

	cout << "\n\n";

	cout << "Array - " << size_array << " elements:\n";
	int* BinarySearchTest_array = new int[size_array];
	for (int i = 0; i < size_array; i++)
	{
		BinarySearchTest_array[i] = 20 - i;
	}
	for (int i = 0; i < size_array; i++) {
		cout << BinarySearchTest_array[i] << " ";
	}
	cout << "\nSort the array with InsertionSort:\n";
	InsertionSort(BinarySearchTest_array, size_array);
	for (int i = 0; i < size_array; i++) {
		cout << BinarySearchTest_array[i] << ' ';
	}

	cout << "\nGet the index of '3':\n";
	try {
		cout << BinarySearch(BinarySearchTest_array, size_array, 3);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}
	cout << "\nGet the index of '13':\n";
	cout << "The index of '13' is ";
	try {
		cout << BinarySearch(BinarySearchTest_array, size_array, 13);
	}
	catch (const invalid_argument error) {
		cout << error.what();
	}

	delete[]BinarySearchTest_array;

	cout << "\n\nComparison QuickSort and InsertionSort:\n\n";

	// Examples of QuickSort work for comparison with InsertionSort
	for (int degree = 1; degree < 6; degree++) {
		int size = pow(10, degree);
		int* array = new int[size];
		int first = 0; int last = size - 1;
		long double elapsed_secs = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL)); // clear the random element list of rand()
			for (int i = 0; i < size; i++) array[i] = rand() % 1000;
			clock_t begin = clock();
			QuickSort(array, first, last);
			clock_t end = clock();
			elapsed_secs += long double(end - begin) / CLOCKS_PER_SEC;
		}
		elapsed_secs /= 10;
		cout << "QuickSort of " << size << " element array - " << elapsed_secs << " seconds\n";
		delete[]array;

	}

	cout << "\n";

	// Examples of InsertionSort work for comparison with QuickSort
	for (int degree = 1; degree < 6; degree++) {
		int size = pow(10, degree);
		int* array = new int[size];
		int first = 0; int last = size - 1;
		long double elapsed_secs = 0;
		for (int i = 0; i < 10; i++) {
			srand(time(NULL)); // clear the random element list of rand()
			for (int i = 0; i < size; i++) array[i] = rand() % 1000;
			clock_t begin = clock();
			InsertionSort(array, size);
			clock_t end = clock();
			elapsed_secs += long double(end - begin) / CLOCKS_PER_SEC;
		}
		elapsed_secs /= 10;
		cout << "InsertionSort of " << size << " element array - " << elapsed_secs << " seconds\n";
		delete[]array;
	}

}







