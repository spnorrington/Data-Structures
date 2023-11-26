// Test File for vector class that derives from the base class SeqContainer.hpp


#include <iostream>
#include "seqcontainervector.hpp"
void printItem(int& item) {
	std::cout << item << " ";

int main()
{
	Vector<int> vectorOfIntegers;
	if (vectorOfIntegers.empty())
	{
		std::cout << "YEP, The new vector is empty." << std::endl;
	}

	for (int i = 0; i < 5; i++) 
	{
		vectorOfIntegers.push_back(i * 2);
	}

    std::cout << "Vector elements: ";
    vectorOfIntegers.traverse(printItem);
    std::cout << std::endl;

    std::cout << "Element at index 2: " << vectorOfIntegers.at(2) << std::endl;

    // Modify the element at index 2
    vectorOfIntegers.at(2) = 42;

    std::cout << "Modified vector elements: ";
    vectorOfIntegers.traverse(printItem);
    std::cout << std::endl;

    std::cout << "Vector size: " << vectorOfIntegers.size() << std::endl;

    // Erase the element at index 1
    Vector<int>::iterator eraseItr = vectorOfIntegers.erase(vectorOfIntegers.begin() + 1);

    std::cout << "Vector elements after erasing: ";
    vectorOfIntegers.traverse(printItem);
    std::cout << std::endl;

    // Insert a new element at the beginning
    Vector<int>::iterator insertItr = vectorOfIntegers.insert(vectorOfIntegers.begin(), 99);

    std::cout << "Vector elements after inserting at the beginning: ";
    vectorOfIntegers.traverse(printItem);
    std::cout << std::endl;

    return 0;
}

/*
Instructions:
In lecture, we built a base class for sequential containers  and modified the list, stack, and queue data structures to inherit  from that `SequentialContainer` class.   Modify your `Vector` and  `Array` classes to be derived classes of `SequentialContainer`,    noting that for both classes you will be able to build the iterator   using the vector or array indexes.
*/