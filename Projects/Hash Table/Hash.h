/*
*I Joshua Sutherland have not used any code other than my
* own(or that in the textbook) for this project.I also have
* not used any function or data - structure from the Standard
* - Template Library.I understand that any violation of this
* disclaimer will result in a 0 for the project.
*/

#pragma once
#include "Node.h"
#include "List.h"
#include "Iterator.h"
#include <assert.h>

using namespace list_1;

template <typename RecordType>
class Table
{
private:
	list<RecordType> *data;
	static const int TABLE_SIZE = 255;

public:
	Table()
	{
		data = new list<RecordType>[TABLE_SIZE];
	};

	~Table()
	{
		delete [] data;
	};

	void clear()
	{
		delete [] data;
		data = new list<RecordType>[TABLE_SIZE];
	};

	void insert(RecordType record, std::string name)
	{
		list<RecordType> *insertList = &data[hash(name)];
		insertList->add_back(record, name);
	};

	unsigned char hash(std::string key)
	{
		const int shift = 1;
		const int bitSize = sizeof(unsigned char);

		unsigned char hash_total = 1;
		for (int i = 0; i < (int)key.length(); i++)
		{
			unsigned char helper = (unsigned char) key[i];
			hash_total = (hash_total * helper) >> (bitSize - shift);
		}
		return hash_total - 1;
	};

	RecordType retrieve(std::string key)
	{
		list<RecordType> *retrieveList = &data[hash(key)];
		Iterator<RecordType> it = retrieveList->begin();
		while (it.is_item())
		{
			if (it.get_name() == key)
			{
				return *it;
			};
			++it;
		};
	};

	RecordType& operator[](std::string key)
	{
		RecordType record = retrieve(key);
		return record;
	};

};