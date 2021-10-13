/*
*I Joshua Sutherland have not used any code other than my
* own(or that in the textbook) for this project.I also have
* not used any function or data - structure from the Standard
* - Template Library.I understand that any violation of this
* disclaimer will result in a 0 for the project.
*/

#include "Iterator.h"

using namespace std;

namespace list_1
{
	Iterator::Iterator(Node *np)
	{
		n = np;
	};

	void Iterator::operator++()
	{
		if (is_item())
			n = n->next;
	};

	bool Iterator::is_item()
	{
		if (n)
			return true;
		else
			return false;
	};

	int Iterator::operator*()
	{
		if (is_item())
			return n->data;
	};
}