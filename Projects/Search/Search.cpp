/* I Joshua Sutherland have not used any code other than
* my own(or that in the textbook) for this project. I also
* have not used any function or data structure from the
* Standard Template Library. I understand that any violation
* of this disclaimer will result in a 0 for the project.
*/

#include "Search.h"
#include <random>

using namespace std;

Search::Search(int size, int seed)
{
	arraySize = size;
	array = new int[size];
	set_seed(seed);
}

Search::~Search()
{
	delete array;
	array = NULL;
}

void Search::init_array()
{
	array[0] = rand() % arraySize;
	for (int i = 0; i < arraySize; i++)
		array[i] = rand() % arraySize;
}

void Search::init_sorted_array()
{
	array[0] = rand() % 5;
	for (int i = 1; i < arraySize; i++)
		array[i] = array[i-1] + rand() % 5;
}

void Search::set_seed(int seed)
{
	srand(seed);
}

int Search::getSize()
{
	return arraySize;
}

bool Search::sequential_find(int num)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (num == array[i])
			return true;
	}
	return false;
}

bool Search::recursive_binary_find(int num)
{
	if (array[0] > array[arraySize - 1])
		return false;

	int mid = (int) ((0 + (arraySize - 1) / 2));

	if (num == array[mid])
		return true;
	if (num < array[mid])
		return recursive_binary_find(num, 0, mid - 1);
	else
		return recursive_binary_find(num, mid + 1, arraySize);
}

bool Search::recursive_binary_find(int num, int first, int last)
{
	if (first > last)
		return false;
	int mid = int((first + last) / 2);
	if (num == array[mid])
		return true;
	if (num < array[mid])
		return recursive_binary_find(num, first, mid - 1);
	else
		return recursive_binary_find(num, mid + 1, last);
}

bool Search::iterative_binary_find(int num)
{
	int first = 0;
	int last = arraySize;
	bool found = false;
	
	while (first <= last && !found)
	{
		int index = (int) ((first + last) / 2);
		if (num == array[index])
			return found = true;
		else if (num < array[index])
			last = index - 1;
		else if (num > array[index])
			first = index + 1;
	}
	return false;
}