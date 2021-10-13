/* I Joshua Sutherland have not used any code other than
* my own(or that in the textbook) for this project. I also
* have not used any function or data structure from the
* Standard Template Library. I understand that any violation
* of this disclaimer will result in a 0 for the project.
*/

#include "Sort.h"
#include <random>

Sort::Sort(int size)
{
	arraySize = size;
	array = new int[size];
	temp = new int[size];
	set_seed(SEED_SIZE % size);
}

Sort::~Sort()
{
	delete array;
	array = nullptr;
}

void Sort::init_array()
{
	array[0] = rand() % arraySize;
	for (int i = 0; i < arraySize; i++)
		array[i] = rand() % arraySize;
}

void Sort::set_seed(int seed)
{
	srand(seed);
}

void Sort::selectionsort(int data[], int n)
// Library facilities used: algorithm, cstdlib
{
	int i, j, index_of_largest;
	int largest;

	if (n == 0)
		return; // No work for an empty array.

	for (i = n - 1; i > 0; --i)
	{
		largest = data[0];
		index_of_largest = 0;
		for (j = 1; j <= i; ++j)
		{
			if (data[j] > largest)
			{
				largest = data[j];
				index_of_largest = j;
			}
		}
		swap(data[i], data[index_of_largest]);
	}
}

void Sort::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort::mergesort(int data[], int n)
// Precondition: data is an array with at least n components.
// Postcondition: The elements of data have been rearranged so
// that data[0] <= data[1] <= ... <= data[n-1].
// NOTE: If there is insufficient dynamic memory, thenbad_alloc is thrown.
// Library facilities used: cstdlib
{
	int n1; // Size of the first subarray
	int n2; // Size of the second subarray

	if (n > 1)
	{
		// Compute sizes of the subarrays.
		n1 = n / 2;
		n2 = n - n1;

		mergesort(data, n1);         // Sort from data[0] through data[n1-1]
		mergesort((data + n1), n2);  // Sort from data[n1] to the end

		// Merge the two sorted halves.
		merge(data, n1, n2);
	}
}

void Sort::merge(int data[], int n1, int n2)
// Precondition: data is an array (or subarray) with at least n1 + n2 elements.
// The first n1 elements (from data[0] to data[n1 - 1]) are sorted from
// smallest to largest, and the last n2 (from data[n1] to data[n1 + n2 - 1])
// also are sorted from smallest to largest.
// Postcondition: The first n1 + n2 elements of data have been rearranged to be
// sorted from smallest to largest.
// NOTE: If there is insufficient dynamic memory, then bad_alloc is thrown.
// Library facilities used: cstdlib
{
	int *temp;          // Points to dynamic array to hold the sorted elements
	int copied = 0; // Number of elements copied from data to temp
	int copied1 = 0; // Number copied from the first half of data
	int copied2 = 0; // Number copied from the second half of data
	int i;           // Array index to copy from temp back into data

	// Allocate memory for the temporary dynamic array.
	temp = new int[n1 + n2];

	// Merge elements, copying from two halves of data to the temporary array.
	while ((copied1 < n1) && (copied2 < n2))
	{
		if (data[copied1] < (data + n1)[copied2])
			temp[copied++] = data[copied1++];        // Copy from first half
		else
			temp[copied++] = (data + n1)[copied2++]; // Copy from second half
	}

	// Copy any remaining entries in the left and right subarrays.
	while (copied1 < n1)
		temp[copied++] = data[copied1++];
	while (copied2 < n2)
		temp[copied++] = (data + n1)[copied2++];

	// Copy from temp back to the data array, and release temp's memory.
	for (i = 0; i < n1 + n2; i++)
		data[i] = temp[i];
	delete[] temp;
}



void Sort::quicksort(int data[], int n)
// Library facilities used: cstdlib
{
	int pivot_index; // Array index for the pivot element
	int n1;          // Number of elements before the pivot element
	int n2;          // Number of elements after the pivot element

	if (n > 1)
	{
		// Partition the array, and set the pivot index.
		partition(data, n, pivot_index);

		// Compute the sizes of the subarrays.
		n1 = pivot_index;
		n2 = n - n1 - 1;

		// Recursive calls will now sort the subarrays.
		quicksort(data, n1);
		quicksort((data + pivot_index + 1), n2);
	}
}

void Sort::partition(int data[], int n, int& pivot_index)
// Library facilities used: itemtool.h, stdlib.h
//
// NOTES FROM THE IMPLEMENTOR:
// How the partition works on small arrays:
//
// Notice that n=0 is not permitted by the precondition.
//
// If n=1, then too_big_index is initialized as 1, and too_small_index is
// initialized as 0. Therefore, the body of the loop is never executed,
// and after the loop pivot_index is set to zero.
//
// If n=2, then both too_big_index and too_small_index are initialized as 1.
// The loop is entered, and there are two cases to consider:
// -- if data[1] <= pivot, then too_big_index increases to 2, and
//    too_small_index stays at 1. The if-statement at the bottom of the loop
//    is then skipped, and after the loop we copy data[1] down to data[0],
//    and copy the pivot into data[0]. Thus, the smaller element is in
//    data[0], and the larger element (the pivot) is in data[1].
// -- if data[1] > pivot, then too_big_index stays at 1, and too_small_index
//    decreases to 0. The if-statement at the bottom of the loop is then
//    skipped, and after the loop we end up copying the pivot onto data[0]
//    (leaving data[1] alone). Thus, the smaller element (the pivot) remains
//    at data[0], leaving the larger element at data[1].
{
	int pivot = data[0];
	int too_big_index = 1;			// index of first item after pivot
	int too_small_index = n - 1;	// index of last item

	while (too_big_index <= too_small_index)
	{
		while (too_big_index < n && data[too_big_index] <= pivot)
			too_big_index++;

		while (data[too_small_index] > pivot)
			too_small_index--;

		if (too_big_index < too_small_index)
			swap(data[too_big_index], data[too_small_index]);
	}

	pivot_index = too_small_index;
	data[0] = data[pivot_index];
	data[pivot_index] = pivot;

}

void Sort::insertionsort(int data[], int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		j = i;
		while (j > 0 && data[j - 1] > data[j])
		{
			tmp = data[j];
			data[j] = data[j - 1];
			data[j - 1] = tmp;
			j--;
		}
	}
}