/*
*I Joshua Sutherland have not used any code other than my
* own(or that in the textbook) for this project.I also have
* not used any function or data - structure from the Standard
* - Template Library.I understand that any violation of this
* disclaimer will result in a 0 for the project.
*/

#pragma once
#include <string>

namespace list_1
{
	template <typename RecordType>
	struct Node
	{
		RecordType data;
		std::string symbol;
		Node<RecordType> *next;

		// Constructor
		// Postcondition: 
		Node<RecordType>(RecordType d, std::string name)
		{ 
			data = d;
			symbol = name;
			next = nullptr;
		};
	};
}