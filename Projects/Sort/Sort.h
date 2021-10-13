/* I Joshua Sutherland have not used any code other than
* my own(or that in the textbook) for this project. I also
* have not used any function or data structure from the
* Standard Template Library. I understand that any violation
* of this disclaimer will result in a 0 for the project.
*/

#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class Sort
{
public:
	Sort(int size);
	~Sort();

	int arraySize;
	int* array;
	int* temp;
	const int SEED_SIZE = 3000;

	void init_array();

	void set_seed(int seed);

	// PROTOTYPE of the function used in this test program:
	void selectionsort(int data[], int n);
	// Precondition: data is an array with at least n components.
	// Postcondition: The elements are rearranged so that
	// data[0] <= data[1] <= ... <= data[n-1]

	// MergeSort
	// PROTOTYPES of the functions used in this test program:
	void mergesort(int data[], int n);
	// Precondition: data is an array with at least n components.
	// Postcondition: The elements of data have been rearranged so
	// that data[0] <= data[1] <= ... <= data[n-1].
	// NOTE: If there is insufficient dynamic memory, then new_handler is called.

	void merge(int data[], int n1, int n2);
	// Precondition: data is an array (or subarray) with at least n1+n2 elements. 
	// The first n1 elements (from data[0] to data[n1-1]) are sorted from smallest 
	// to largest, and the last n2 (from data[n1] to data[n1+n2-1]) are also 
	// sorted from smallest to largest.
	// Postcondition: The first n1+n2 elements of data have been
	// rearranged to be sorted from smallest to largest.
	// NOTE: If there is insufficient dynamic memory, then new_handler is called.

	// QuickSort
	// PROTOTYPES of the functions used in this test program:
	void quicksort(int data[], int n);
	// Precondition: data is an array with at least n components.
	// Postcondition: The elements of data have been rearranged so
	// that data[0] <= data[1] <= ... <= data[n-1].

	void partition(int data[], int n, int& pivot_index);
	// Precondition: n > 1, and data is an array (or subarray)
	// with at least n elements.
	// Postcondition: The function has selected some "pivot value"
	// that occurs in data[0]..data[n-1]. The elements of data
	// have then been rearranged, and the pivot index set so that:
	//   -- data[pivot_index] is equal to the pivot;
	//   -- Each item before data[pivot_index] is <= the pivot;
	//   -- Each item after data[pivot_index] is >= the pivot.

	void insertionsort(int data[], int n);

	friend ostream& operator<< (ostream& out, const Sort& s)
	{
		// put the code in here.
		for (int i = 0; i < s.arraySize; i++)
			out << s.array[i] << ' ';
		return out;
	}

private:
	void swap(int& a, int& b);
};

