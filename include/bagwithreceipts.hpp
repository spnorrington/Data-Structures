// Assignment 2 Part 3
// Modify the following:
// File:   bag.h
// Author: Dr. Adam Lewis
// Suppose we adjust the definition of the `Bag` class to implement a *bag with receipts*. This bag operates in the same matter as with regular bags except the insert function returns a unique integer known as a *receipt*. On deletion, you must pass the remove function a copy of this
//receipt.The function removes the item matching the receipt and returns a reference to the removed item.Implement the `ReceiptBag` class, with appropriate test scripts, in your library that implements this ADT

#pragma once
#include <iostream>
#include "vector.h"

template <typename Thing>
class Bag {
public:
    void insert(Thing aThing) {
        bagContents.push_back(aThing);
        bagSize++;
    }
    Thing& pop() {
        Thing aThing;
        if (bagContents.size() > 0) {
            aThing = bagContents[bagSize];
            bagSize--;
        }
        else {
            std::cerr << "Can't pop out of an empty bag" << std::endl;
        }
        return aThing;
    }
    int size() {
        return bagSize;
    }
    int count(Thing aThing) {
        int bagCount = 0;
        for (int i = 0; i < bagSize; i++) {
            if (bagContents[i] == aThing) {
                bagCount++;
            }
        }
        return bagCount;
    }
private:
    vector<Thing> bagContents;
    int bagSize = 0;
};
