// 
// This file was written by my instructor Adam Lewis at Athens State University
// Original File is currently located at https://github.com/adamwadelewis/cs372.lewis.fa23/blob/main/apps/listtest/listtest.cpp
// This is a sample test file for the List class, I will be using this to test my own implementation of the List Class and Bag Class
// File: listtest.cpp
// Author:  <adam.lewis@athens.edu>

// MODULE 3 ASSIGNMENT PART 2 //////
/////////////////////

#include <iostream>
#include "List.h"
#include "Bag.h"

void printItem(int& item)
{
    std::cout << item << " ";
}

int main() 
{
    Bag<int> aListOfIntegers;
    if (aListOfIntegers.empty())
    {
        std::cout << "Yep, the new list is empty. " << std::endl;
    }
    for (int i = 3; i >= 0; i--)
    {
        aListOfIntegers.push_front(i);
    }
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;

    std::cout << "Test iterators: Mutable -> ";
    for (auto iter = aListOfIntegers.begin();
        iter != aListOfIntegers.end();
        ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << "Test iterators: const -> ";
    for (auto iter = aListOfIntegers.cbegin();
        iter != aListOfIntegers.cend();
        ++iter)
    {
        std::cout << *iter << " ";
    }

    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        int datum = aListOfIntegers.back();
        std::cout << datum << " ";
        aListOfIntegers.pop_back();
    }
    std::cout << std::endl;
    if (!aListOfIntegers.empty())
    {
        aListOfIntegers.traverse(printItem);
        std::cout << std::endl;
    }
    aListOfIntegers.push_back(42);
    aListOfIntegers.traverse(printItem);
    std::cout << std::endl;
    return 0;
}