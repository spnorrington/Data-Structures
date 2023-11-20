// Instructions: The C++ standard claims that sort() algorithm in the standard template library has performance equal to Quicksort in the average case.  

//Let's test that by writing a template function version of Quicksort that will sort the contents of a vector of the template type.
//
//Then write a program that use the C++ STL chrono library(as you did for the Towers of Hanoi problem at the start of semester) that randomly generates vectors of 100, 500, 1000, 5000, and 10000 integers, times how long it takes your Quicksort function to sort each vector and then times how long it takes the std::sort() function from the STL algorithms library to sort the same vector.
// 

// File: quicksort.hpp

#pragma once
#include <vector>

template <typename T>
int partition(T a[], int start, int end) 
{
    // Pick the rightmost element as a pivot from the array
    T pivot = a[end];
    // elements less than the pivot goes to the left of `pIndex`
    // elements more than the pivot goes to the right of `pIndex`
    // equal elements can go either way
    int pIndex = start;

    // Iterate through the array to partition elements
    for (int i = start; i < end; i++) 
    {
        if (a[i] <= pivot) 
        {
            // Swap elements less than or equal to pivot
            std::swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    // swap `pIndex` with pivot
    std::swap(a[pIndex], a[end]);
    // return `pIndex` (index of the pivot element)
    return pIndex;
}

// Function to recursively sort the array using the quicksort algorithm
template <typename T>
void quicksort(T arr[], int low, int high) 
{
    if (low < high) 
    {
        // Use the partition function 
        int s = partition(arr, low, high);
        quicksort(arr, low, s - 1);
        quicksort(arr, s + 1, high);
    }
}


