/*
 * I Joshua Sutherland, Section 001, have not used any code other than my 
 * own(or that in the textbook) for this project.I also have not used any 
 * function or data - structure from the Standard - Template Library. I 
 * understand that any violation of this disclaimer will result in a 0 for 
 * the project.
 */

#include "sequence.h"
using namespace std;

namespace main_savitch_4{

	sequence::sequence(int initial_capacity)
	{
		used = 0;
		current_index = 0;
		capacity = initial_capacity;
		data = new value_type[initial_capacity]();
	};

	sequence::sequence(const sequence& source)
	{
		used = source.used;
		current_index = source.current_index;
		capacity = source.capacity;
		data = new value_type[source.capacity];
		for (int i = 0; i < source.used; i++)
		{
			data[i] = source.data[i];
		}
	};

	sequence::~sequence()
	{
		delete [] data;
	};

	void sequence::resize(int new_capacity)
	{
		value_type *larger_array;

		if (new_capacity == capacity)
			return;

		if (new_capacity < used)
			new_capacity = used;

		larger_array = new value_type[new_capacity];
		
		for (int i = 0; i < used; i++)
		{
			larger_array[i] = data[i];
		}

		//delete [] data;	// doesn't like my delete... hmmm....
		data = larger_array;
		capacity = new_capacity;
	};

	void sequence::start()
	{
		//First item becomes the current item
		if (used > 0)
			current_index = 0;

		// if sequence is empty, no current item
		else if (current_index == capacity)
			current_index = -1;
	};

	void sequence::advance()
	{
		if (is_item())
		{
			if (current_index == used - 1)
				current_index = -1;

			else
				current_index++;
		}
	};

	void sequence::insert(const value_type& entry)
	{
		if (current_index == -1)
			current_index = 0;
		if (used == capacity)
			resize(used + DEFAULT_CAPACITY);

		// if current_index is the start, add the data to the start
		for (int i = used + 1; i > current_index; i--)
		{
			data[i] = data[i - 1];
		}
		data[current_index] = entry;
		used++;
	};

	void sequence::attach(const value_type& entry)
	{
		if (used == capacity)
			resize(used + DEFAULT_CAPACITY);
		data[used] = entry;
		used++;
	};

	void sequence::remove_current()
	{
		if (!is_item())
			return;

		// starts at the position of the current index
		for (int i = current_index; i < used; i++)
		{
			data[i] = data[i + 1];
		}
		
		// if you deleted the last item, make sure that the current index is -1
		if (used == 0)
			current_index = -1;

		used--;
	};

	void sequence::operator =(const sequence& source)
	{
		value_type *new_data;
		value_type *old_data = source.data;

		if (this == &source)
			return;

		if (capacity != source.capacity)
		{
			capacity = source.capacity;
		}

		new_data = new value_type[source.capacity];
		delete [] data;
		data = new_data;
		used = source.used;

		while (old_data != (old_data + used))
		{
			*data = *old_data;
			++data;
			++old_data;
		}

		delete [] old_data;
	};

	int sequence::size() const
	{
		return used;
	}

	bool sequence::is_item() const
	{
		// if it is an item, ci >= 0, 
		if (used > 0 && current_index >= 0 && current_index <= used)
		{
			return true;
		}
		else
			return false;
	}

	value_type sequence::current() const
	{
		if (is_item())
			return data[current_index];
	}
}