// File: Midterm question #2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Using either the STL stack class or your own Stack class, write a small program that, given a string input by the user from the keyboard, will tell the user whether or not the string contains a matching number of parentheses.
// The following references were used:
// https://en.cppreference.com/w/cpp/container/list
// https://en.wikipedia.org/wiki/Quicksort
//

#include <iostream>
#include <list>
#include <stack>
#include <string>

template <typename T>
void partitionList(const T& splittingValue, const std::list<T>& originalList, std::list<T>* lessList, std::list<T>* greaterList)
{
    for (const auto& item : originalList)
    {
        if (item < splittingValue)
        {
            lessList->push_back(item);
        }
        else {
            greaterList->push_back(item);
        }
    }
}

template <typename T>
std::list<T>* quicksort(const std::list<T>& inputList)
{
    if (inputList.size() <= 1)
    {
        return new std::list<T>(inputList);  // Base case: already sorted or empty list
    }

    const T& splittingValue = inputList.front();  // Choose the first element as the pivot
    std::list<T> lessList;
    std::list<T> greaterList;

    // Partition the list
    partitionList(splittingValue, inputList, &lessList, &greaterList);

    // Recursive calls for the two partitions
    std::list<T>* sortedLess = quicksort(lessList);
    std::list<T>* sortedGreater = quicksort(greaterList);

    // Combine the results into a dynamically allocated STL list
    sortedLess->push_back(splittingValue);
    sortedLess->splice(sortedLess->end(), *sortedGreater);

    delete sortedGreater;  // Free memory

    return sortedLess;
}

bool isBalanced(const std::string& expression) {
    const char LEFTPAREN = '(';
    const char RIGHTPAREN = ')';
    std::stack<char> store;
    char next;
    bool failed = false;
    for (std::string::size_type i = 0; !failed && (i < expression.length()); ++i) {
        next = expression[i];
        if (next == LEFTPAREN) {
            store.push(next);
        }
        else if ((next == RIGHTPAREN) && !store.empty()) {
            store.pop();
        }
        else if ((next == RIGHTPAREN) && store.empty()) {
            failed = true;
        }
    }
    return (store.empty() && !failed);
}

int main() {
    // Example usage
    std::list<int> inputList = { 5, 2, 9, 1, 5, 6 };

    // Check for balanced parentheses in the expression
    std::string expression = "((5+2)*(9-1))";
    if (isBalanced(expression)) {
        std::cout << "Expression has balanced parentheses.\n";
        std::list<int>* sortedList = quicksort(inputList);

        // Output the sorted list
        std::cout << "Sorted List: ";
        for (const auto& item : *sortedList)
        {
            std::cout << item << " ";
        }
        std::cout << std::endl;

        delete sortedList;  // Free memory
    }
    else {
        std::cout << "Expression has unbalanced parentheses.\n";
    }

    return 0;
}





