// Container Classes 
#include <iostream>
#include <set>
#include "bag.hpp"

bool fncomp(int lhs, int rhs) { return lhs < rhs; }
struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs < rhs;
	}
};

int main()
{
	/**
 * Construct the IntCell with initialValue
 */
	IntCell::IntCell(int initialValue) : storedValue{ initialValue }
	{
	}

	/**
	 * Return the stored value.
	 */
	int IntCell::read() const
	{
		return storedValue;
	}

	/**
	 * Store x.
	 */
	void IntCell::write(int x)
	{
		storedValue = x;
	}


	Bag<float> aBag = new Bag<Float>();
	aBag.insert(3.14);
	aBag.insert(100000.0);
	int itemCount = aBag.size();
	float newItem = aBag.pop();
	int main()
	{
		// empty set of ints
		std::set<int> first;
		int myints[] = { 10,20,30,40,50 };
		// range
		std::set<int> second(myints, myints + 5);
		// a copy of second
		std::set<int> third(second);
		// iterator ctor.
		std::set<int> fourth(second.begin(), second.end());
		// class as Compare
		std::set<int, classcomp> fifth;
		// function pointer as Compare
		bool(*fn_pt)(int, int) = fncomp;
		std::set<int, bool(*)(int, int)> sixth(fn_pt);
		return 0;
	}

return 0;
}


// Instructions: Suppose we adjust the definition of the `Bag` class to implement a *bag with receipts*. This bag operates in the same matter as with regular bags except the insert function returns a unique integer known as a *receipt*. On deletion, you must pass the remove function a copy of this
//receipt.The function removes the item matching the receipt and returns a reference to the removed item.Implement the `ReceiptBag` class, with appropriate test scripts, in your library that implements this ADT

//(HINTS : (1) This is a good application of the parallel arrays concept we introduced in CS 318. (2) you will need to determine what to do when you pull something from the bag.)