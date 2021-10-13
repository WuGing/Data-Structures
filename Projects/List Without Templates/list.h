#ifndef LIST_H
#define LIST_H
#include "Node.h"
#include "Iterator.h"

namespace list_1
{
	class list
    {
    public:

        // CONSTRUCTOR
        list( );
		// postcondition: all nodes in the list are destroyed.
		~list();
        // MODIFICATION MEMBER FUNCTIONS
		//postcondition: entry is added to the front of the list
        void insert_front(const int& entry);
        //postcondition: entry is added to the back of the list
        void add_back(const int& entry);
		// postcondition: all nodes with data == entry are removed from the list
        void remove_all(const int& entry);
		// postcondition: an iterator is created pointing to the head of the list
		Iterator begin(void);
		
		// CONSTANT MEMBER FUNCTIONS
		// postcondition: the size of the list is returned
        int size( ) const;
    private:
		Node* head;
	};

}

#endif

