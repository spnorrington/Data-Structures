// quicksort.hpp

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
    // each time we find an element less than or equal to the pivot, `pIndex`
    // is incremented, and that element would be placed before the pivot.
    for (int i = start; i < end; i++) 
    {
        if (a[i] <= pivot) 
        {
            std::swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    // swap `pIndex` with pivot
    std::swap(a[pIndex], a[end]);
    // return `pIndex` (index of the pivot element)
    return pIndex;
}

template <typename T>
void quicksort(T arr[], int low, int high) 
{
    if (low < high) 
    {
        // Use the partition function from the notes
        int s = partition(arr, low, high);
        quicksort(arr, low, s - 1);
        quicksort(arr, s + 1, high);
    }
}


