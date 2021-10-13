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

class Search
{
public:
	bool sequential_find(int num);
	bool recursive_binary_find(int num);
	bool recursive_binary_find(int num, int first, int last);
	bool iterative_binary_find(int num);

	void init_array();
	void init_sorted_array();
	void set_seed(int seed);
	int getSize();

	// this is just for practice and debugging.
	friend ostream& operator<< (ostream& out, const Search& s)
	{
		// put the code in here.
		for (int i = 0; i < s.arraySize; i++)
			out << s.array[i] << ' ';
		return out;
	}

	Search(int size, int seed=0);
	~Search();

private:

	int arraySize;
	int* array;
};

