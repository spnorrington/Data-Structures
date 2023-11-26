// Assignment 2 Part 3
// Modify the following:
// File:   bag.h
// Author: Dr. Adam Lewis
// Suppose we adjust the definition of the `Bag` class to implement a *bag with receipts*. This bag operates in the same matter as with regular bags except the insert function returns a unique integer known as a *receipt*. On deletion, you must pass the remove function a copy of this
//receipt.The function removes the item matching the receipt and returns a reference to the removed item.Implement the `ReceiptBag` class, with appropriate test scripts, in your library that implements this ADT

#pragma once
#include "vector.hpp"
#include <iostream>

template <typename Thing>
class ReceiptBag 
{
public:
    int insert(Thing aThing) 
    {
        bagContents.push_back(aThing);
        bagSize++;
        return nextReceipt++;
    }
    // The `remove` function takes a receipt and removes the corresponding item
       // It returns a reference to the removed item
    Thing& remove(int receipt) 
    {
        Thing aThing;
        bool found = false;

        // Iterate through the bag to find the item with the given receipt
        for (int i = 0; i < bagSize; i++) 
        {
            if (receipts[i] == receipt) 
            {
                aThing = bagContents[i];
                found = true;

                // Remove the item from the bag
                bagContents.erase(i);
                receipts.erase(i);
                bagSize--;

                break;
            }
        }
        // If the receipt is not found, print an error message
        if (!found) {
            std::cerr << "Item with receipt " << receipt << " not found in the bag" << std::endl;
        }
        return aThing;
    }

    // Get the current size of the bag
    int size() const 
    {
        return bagSize;
    }

    // Get the count of a specific item in the bag
    int count(Thing aThing) const 
    {
        int bagCount = 0;
        for (int i = 0; i < bagSize; i++) 
        {
            if (bagContents[i] == aThing) 
            {
                bagCount++;
            }
        }
        return bagCount;
    }

private:
    Vector<Thing> bagContents;  // Using your Vector class for the bag contents
    Vector<int> receipts;  // Vector to store receipts corresponding to items
    int bagSize = 0;
    int nextReceipt = 1;  // The next available receipt number
};