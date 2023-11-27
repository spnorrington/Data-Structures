//
// File:   receiptbag.hpp
// Receipt bag class container
// Source code from Professor Dr. Adam Lewis
//
#pragma once
#include <iostream>
#include "vector.hpp"



template <typename Thing>
class Bag {
public:
    // must return unique int known as a receipt
    // On deletion, you must pass the remove function a copy of this

    // Insert a Thing into the bag
    void insert(Thing aThing) 
    {
        bagContents.push_back(aThing); // uses the push_back method of the vector
        bagSize++; // increment the bag size

    }
    // Remove and return the last Thing in the bag
    Thing& pop() 
    {
        Thing aThing;
        if (bagContents.size() > 0) 
        {
            aThing = bagContents[bagSize]; //access the last element in the vector
            bagSize--; // decrement the size of the bag
        }
        else 
        {
            std::cerr << "Can't pop out of an empty bag" << std::endl;
        }
        return aThing; // return the removed element
    }
    // get the current size of the bag
    int size() 
    {
        return bagSize;
    }
    // count occurences of a specfic item in the bag
    int count(Thing aThing) 
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

    // Data members (attributes) are typically declared private
    // This is because the object is accessed through the public member functions, whose viewable behavior remains unchanged
private:
    vector<Thing> bagContents; // vector to hold the bag contents
    int bagSize = 0; // size of the bag
};

template <typename Thing>
class ReceiptBag 
{
public:
    // Insert an element into the bag and return a unique receipt
    int insert(Thing aThing) 
    {
        int receipt = nextReceipt++; // Get the next available receipt
        bagContents.insert(aThing); // Use the insert method of the vector
        receipts.push_back(receipt); // Use push_back to add the receipt to the receipts vector
        return receipt; // Return the unique receipt
    }

    // remove and return the element matching the receipt
    Thing& remove(int receipt) 
    {
        int index = receipts.index_of(receipt); // find the index of the receipt
        if (index != -1) 
        {
            receipts.remove(index);
            return bagContents.pop_at(index); //use pop_at to remove the element at the index
        }
        else 
        {
            std::cerr << "Invalid receipt" << std::endl;
            // You may want to handle the error differently, such as throwing an exception.
            // For simplicity, I'm printing an error message here.
            exit(1);
        }
    }

    // Get the current size of the bag
    int size() const 
    {
        return bagContents.size();
    }

private:
    Bag<Thing> bagContents; // use the Bag class to hold the bag contents
    Vector<int> receipts; // vector to hold the receipts
    int nextReceipt = 1; // track the next available receipt
};

// Notes
//Operations:
// common interface Size and capacity: size(), max_size(), empty(), swap(), and clear()
//Bag() : Create an empty bag.
//insert(Thing aThing)
//pop() : Remove a Thing from the bag
//size() : Number of Things in the bag ?
//count(Thing aThing) : How many specific Things in the bag ?
//
// We know we need to include destructor, copy constructor, and
//assignment when working with clases with dynamically
//allocated members
//Add implementing a move constructor and move assignment
//override to that list

//Important note : The intention with a class is that the only way that
//an object is manipulated is through its public operations.