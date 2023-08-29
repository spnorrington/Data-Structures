// Sophia Norris
// Data Structures
// Assignment 1 Part A
// Description: This program demonstrates what not to do with pointers


#include <iostream>
#include <string>



// Function 1
void demoArrayDelete() 
{
    const int arraySize = 10000; // Large array size
    int* ptr1 = new int[arraySize];  // Dynamically allocate an array of integers


    for (int i = 0; i < arraySize; ++i)
    {
        ptr1[i] = i;
    }

    int* ptr2 = ptr1; // Pointing to the same location

    delete[] ptr1; // Deleting the array

    for (int i = 0; i < 10; ++i) 
    {
        std::cout << ptr2[i] << " "; // Accessing memory after deletion
    }

    std::cout << std::endl;
}

// Function 2
void demoRegularDelete() 
{

    const int arraySize = 1000000; // Large array size
    int* ptr1 = new int[arraySize];

    for (int i = 0; i < arraySize; ++i) 
    {
        ptr1[i] = i;
    }

    int* ptr2 = ptr1; // Pointing to the same location

    delete ptr1; // Regular delete on an array

    std::cout << "Address of ptr2: " << ptr2 << std::endl;

    for (int i = 0; i < 10; ++i) 
    {
        std::cout << ptr2[i] << " "; // Accessing memory with an invalid pointer
    }

    std::cout << std::endl;
}

// Function 3
std::string* allocateStringOnHeap() 
{
    std::string* strPtr = new std::string("abcdefghijkl");
    return strPtr;
}

// Function 4
void demoDanglingStringPointer() 
{
    std::string* strPtr = allocateStringOnHeap(); // Allocate a string and store its pointer
    std::string str = *strPtr; // Dereferencing dangling pointer
    delete strPtr; // Memory leak

    std::cout << "Dangling String: " << str << std::endl;
}

int main() 
{
    std::cout << "Demonstration of Array Delete: " << std::endl;
    demoArrayDelete();

    std::cout << "Demonstration of Regular Delete: " << std::endl;
    demoRegularDelete();

    std::cout << "Demonstration of Dangling String Pointer:" << std::endl;
    demoDanglingStringPointer();

    return 0;
}
