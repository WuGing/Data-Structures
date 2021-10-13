/*
*I Joshua Sutherland have not used any code other than my
* own(or that in the textbook) for this project.I also have
* not used any function or data - structure from the Standard
* - Template Library.I understand that any violation of this
* disclaimer will result in a 0 for the project.
*/

#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Iterator.h"

namespace list_1
{
	template <typename RecordType>
	class list
    {
    public:

        // CONSTRUCTOR
		list()
		{
			head = nullptr;
		};
		// postcondition: all Node<RecordType>s in the list are destroyed.
		~list()
		{
			while (head != nullptr)
			{
				Node<RecordType>* temp = head;
				head = head->next;
				delete temp;
			}
		}
        // MODIFICATION MEMBER FUNCTIONS
		//postcondition: entry is added to the front of the list
		void insert_front(const int& entry)
		{
			if (head == nullptr)
				head = new Node<RecordType>(entry);

			else
			{
				Node<RecordType> *temp = new Node<RecordType>(entry);
				temp->next = head;
				head = temp;
			}
		}
        //postcondition: entry is added to the back of the list
		void add_back(const RecordType& entry, std::string name)
		{
			if (head == nullptr)
				head = new Node<RecordType>(entry, name);

			else
			{
				Node<RecordType> *temp = head;
				while (temp->next != nullptr)
					temp = temp->next;
				temp->next = new Node<RecordType>(entry, name);
			}
		}
		// postcondition: all Node<RecordType>s with data == entry are removed from the list
		void remove_all(const int& entry)
		{
			if (head == nullptr)
				return;
			// special case if item to be removed is at the beginning
			if (head->data == entry)
			{
				if (head->next == nullptr)
				{
					delete[] head;
					head = nullptr;
					return;
				}

				else
				while (head->data == entry)
				{
					Node<RecordType> *temp = head->next;
					delete[] head;
					head = temp;
				}
			}

			// if it is not at the front, then we need to be able to iterate
			// through the list in order to find the places where the value
			// is that of the item being deleted. 

			Node<RecordType> *temp = head;
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
							Node<RecordType> *NN = temp->next;
							temp->next = NN->next;
						}
						else
							temp = temp->next;
					}

				}
			}

			// value at the end
			// We have to know that the value is at the end before we change to it. 

		}
		// postcondition: an iterator is created pointing to the head of the list
		Iterator<RecordType> begin(void)
		{
			Iterator<RecordType> I(head);
			return I;
		}
		
		// CONSTANT MEMBER FUNCTIONS
		// postcondition: the size of the list is returned
		int size() const
		{
			int i = 0;
			Node<RecordType> *temp = head;
			for (; temp != nullptr; i++)
				temp = temp->next;
			return i;
		}

    private:
		Node<RecordType>* head;
	};

}

#endif

