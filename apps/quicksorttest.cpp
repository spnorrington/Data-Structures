//
// Instructions: The C++ standard claims that sort() algorithm in the standard template library has performance equal to Quicksort in the average case.  

//Let's test that by writing a template function version of Quicksort that will sort the contents of a vector of the template type.
//
//Then write a program that use the C++ STL chrono library(as you did for the Towers of Hanoi problem at the start of semester) that randomly generates vectors of 100, 500, 1000, 5000, and 10000 integers, times how long it takes your Quicksort function to sort each vector and then times how long it takes the std::sort() function from the STL algorithms library to sort the same vector.
// 
// quicksort_test.cpp

#include <iostream>
#include <vector>
#include <algorithm> // for std::sort
#include <chrono>
#include "quicksort.hpp"

int main() {
    // Function to generate a random vector of specified size
    auto generateRandomVector = [](int size) {
        std::vector<int> vec;
        for (int i = 0; i < size; i++) {
            vec.push_back(rand() % 1000); // Adjust as needed
        }
        return vec;
    };

    // Vector sizes to test
    std::vector<int> sizes = { 100, 500, 1000, 5000, 10000 };

    for (int size : sizes) {
        // Generate random vectors
        int* arr1 = new int[size];
        std::vector<int> vec2 = generateRandomVector(size);

        // Time your modified Quicksort
        auto start = std::chrono::high_resolution_clock::now();
        quicksort(arr1, 0, size - 1);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Modified Quicksort took " << duration.count() << " seconds for size " << size << std::endl;

        // Time std::sort
        start = std::chrono::high_resolution_clock::now();
        std::sort(vec2.begin(), vec2.end());
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "std::sort took " << duration.count() << " seconds for size " << size << std::endl;

        // Cleanup dynamically allocated array
        delete[] arr1;

        // Add a newline for better readability
        std::cout << std::endl;
    }

    return 0;
}
