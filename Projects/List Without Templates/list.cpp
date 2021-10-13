/*
 *I Joshua Sutherland have not used any code other than my 
 * own(or that in the textbook) for this project.I also have
 * not used any function or data - structure from the Standard 
 * - Template Library.I understand that any violation of this 
 * disclaimer will result in a 0 for the project.
 */

#include "list.h"

using namespace std;

namespace list_1
{
	list::list()
	{
		head = nullptr;
	};

	list::~list()
	{
		delete [] head;
	};

	void list::insert_front(const int& entry)
	{
		if (head == nullptr)
			head = new Node(entry);

		else
		{
			Node *temp = new Node(entry);
			temp->next = head;
			head = temp;
		}
	};

	void list::add_back(const int& entry)
	{
		if (head == nullptr)
			head = new Node(entry);

		else
		{
			Node *temp = head;
			while (temp->next != nullptr)
				temp = temp->next;
			temp->next = new Node(entry);
		}
	};

	void list::remove_all(const int& entry)
	{
		if (head == nullptr)
			return;
		// special case if item to be removed is at the beginning
		if (head->data == entry)
		{
			if (head->next == nullptr)
			{
				delete [] head;
				head = nullptr;
				return;
			}

			else
				while (head->data == entry)
				{
					Node *temp = head->next;
					delete [] head;
					head = temp;
				}
		}

		// if it is not at the front, then we need to be able to iterate
		// through the list in order to find the places where the value
		// is that of the item being deleted. 

		Node *temp = head;
		// values in the middle multiple
		// current item is not entry
		for (; temp != nullptr;)
		{

			if (temp->data != entry && (temp->next == nullptr || temp->next->data != entry))
			{
				temp = temp->next;
			}

			else if (temp->data != entry && temp->next->data == entry)
			{
				while (temp->next != nullptr)
				{
					if (temp->next->data == entry)
					{
						Node *NN = temp->next;
						temp->next = NN->next;
					}
					else
						temp = temp->next;
				}
				
			}
		}

		// value at the end
		// We have to know that the value is at the end before we change to it. 

	};

	Iterator list::begin()
	{
		Iterator I(head);
		return I;
	};

	int list::size() const
	{
		int i = 0;
		Node *temp = head;
		for (; temp != nullptr; i++)
			temp = temp->next;
		return i;
	};
}