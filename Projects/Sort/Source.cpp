/* I Joshua Sutherland have not used any code other than
* my own(or that in the textbook) for this project. I also
* have not used any function or data structure from the
* Standard Template Library. I understand that any violation
* of this disclaimer will result in a 0 for the project.
*/

#include "Sort.h"
#include <ctime>

const int ARRAY_SIZE = 10;

clock_t start = NULL;
double diff = 0;

// used to assign the array to so as to preserve the array for accurate time measurement
const int THOUSAND = 1000;
const int HUNDRED_THOUSAND = 100000;

int main()
{
	Sort sort(ARRAY_SIZE);

	sort.init_array();
	cout << "Array to be sorted (" << ARRAY_SIZE << " elements): " << /*sort <<*/ endl;

	start = clock();
	for (int i = 0; i < THOUSAND; i++)
	{
		sort.temp = sort.array;
		sort.selectionsort(sort.temp, ARRAY_SIZE);
	}
	diff = (difftime(clock(), start) / THOUSAND);
	cout << "Performing a selection sort, the array was sorted in " << (diff * CLOCKS_PER_SEC) << " milliseconds" << endl;

	start = clock();
	for (int i = 0; i < THOUSAND; i++)
	{
		sort.temp = sort.array;
		sort.mergesort(sort.temp, ARRAY_SIZE);
	}
	diff = (difftime(clock(), start) / THOUSAND);
	cout << "Performing a merge sort, the array was sorted in " << (diff * CLOCKS_PER_SEC) << " milliseconds" << endl;

	start = clock();
	for (int i = 0; i < THOUSAND; i++)
	{
		sort.temp = sort.array;
		sort.quicksort(sort.temp, ARRAY_SIZE);
	}
	diff = (difftime(clock(), start) / THOUSAND);
	cout << "Performing a quick sort, the array was sorted in " << (diff * CLOCKS_PER_SEC) << " milliseconds" << endl;

	start = clock();
	for (int i = 0; i < HUNDRED_THOUSAND; i++)
	{
		sort.temp = sort.array;
		sort.insertionsort(sort.temp, ARRAY_SIZE);
	}
	diff = (difftime(clock(), start) / HUNDRED_THOUSAND);
	cout << "Performing a insertion sort, the array was sorted in " << (diff * CLOCKS_PER_SEC) << " milliseconds" << endl;

	system("PAUSE");
	return 0;
}