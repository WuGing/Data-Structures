/* I Joshua Sutherland have not used any code other than
* my own(or that in the textbook) for this project. I also
* have not used any function or data structure from the
* Standard Template Library. I understand that any violation
* of this disclaimer will result in a 0 for the project.
*/

#include "Search.h"
#include <iostream>
#include <ctime>

using namespace std;

const char SEQUENTIAL = 0;
const char RECURSIVE = 1;
const char ITERATIVE = 2;

const char SEED = 3;

const int ARRAY_SIZE = 10000000;
const int LOOP_FIFTY_THOUSAND = 50000;
const int LOOP_TEN_THOUSAND = 10000;
const int LOOP_THOUSAND = 1000;

void PerformSearch(Search& s, char searchType);

int main()
{
	Search search(ARRAY_SIZE, SEED);

	// create an unsorted array
	search.init_array();
	// print out the first unsorted array
	// cout << search << endl;

	cout << "Unsorted array" << endl;
	PerformSearch(search, SEQUENTIAL);

	cout << " " << endl;

	// create a sorted array
	search.init_sorted_array();
	// print out the first unsorted array
	// cout << search << endl;

	cout << "Sorted array" << endl;

	PerformSearch(search, RECURSIVE);

	PerformSearch(search, ITERATIVE);
	
	system("PAUSE");
	return 0;
}

void PerformSearch(Search& s, char searchType)
{
	char* executionType = NULL;
	bool numFound = 0;
	int num = 0;

	clock_t start = NULL;
	clock_t end = NULL;
	double diff = 0;

	switch (searchType)
	{
		
	case SEQUENTIAL:
		start = clock();
		for (int i = 0; i < LOOP_THOUSAND; i++)
		{
			num = rand() % ARRAY_SIZE;
			s.sequential_find(num);
		}
		end = clock();
		diff = (difftime(end, start) / LOOP_THOUSAND);
		executionType = "sequential";
		break;

	case RECURSIVE:
		start = clock();
		for (int i = 0; i < LOOP_FIFTY_THOUSAND; i++)
		{
			num = rand() % ARRAY_SIZE;
			s.recursive_binary_find(num);
		}
		end = clock();
		diff = (difftime(end, start) / LOOP_FIFTY_THOUSAND);
		executionType = "recursive";
		break;

	case ITERATIVE:
		start = clock();
		for (int i = 0; i < LOOP_FIFTY_THOUSAND; i++)
		{
			num = rand() % ARRAY_SIZE;
			s.iterative_binary_find(num);
		}
		end = clock();
		diff = (difftime(end, start) / LOOP_FIFTY_THOUSAND);
		executionType = "iterative";
		break;

	default:
		break;
	}

	cout << "System performed a " << executionType << " search and took an average of "
			<< (diff * (CLOCKS_PER_SEC)) << " micro-seconds." << endl;

}