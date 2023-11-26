//
// File: vector.hpp
// Simplified version of the C++ STL vector class created by Professor Dr. Adam Lewis
// including code in library for implementations of vector class functions
// This code is an example of an implementation of a dynamic array
// 
// Information //
// Dynamic Memory Allocation: The use of new to allocate memory for an array of elements.
// Dynamic Resizing :The push_back function that expands the array when its capacity is reached.
//
// Index Access and Bounds Checking : Accessing elements using the at function with bounds checking.
//
// Copy Constructor and Assignment Operator : Copy constructor and assignment operator to handle proper copying of elements



#pragma once
#include <iostream>

template <typename T>
class Vector
{
public:
	// Default Constructor
	Vector()
	{
		arr = new T[1]; // Initalize array with 1 element
		vCapacity = 1;  // Initalize capacity to 1
		length = 0;  // Initalize length
	}
	// Copy Constructor
	Vector(const Vector& obj)
	{
		this->arr = new T[obj.capacity()]; //allocate memory
		for (int i = 0; i < obj.size(); i++)
		{
			this->put(i, obj.at(i)); //copy elements from the source object
		}
	}
	// Destructor
	~Vector()
	{
		delete[] arr; //free memory
		arr = nullptr; //set to null to avoid dangling pointer
	}

	// Insert data at a specfic index
	void put(T data, int index)
	{
		if (index == vCapacity)
		{
			push_back(T data); // if index is equal to capacity, push back
		}
		else
		{
			arr[index] = data; // else insert data at index
		}
	}

	// add an element to the end of the vector
	void push_back(T data)
	{
		// if number of elements is equal to capacity
			// than we need to reallocate and deep copy
		if (length == vCapacity)
		{
			expand(2 * vCapacity); // double the capacity
		}
		arr[length] = data; // add the new element
		length++;
	}

	// access an element at a specific index
	T &at(int index)
	{
		if (index < 0 || index >= length)
		{
			std::cerr << "Vector: index out of bounds on access" << std::endl;
			exit(1); // Display error message and exit if index is out of bounds
		}
		else
		{
			return arr[index]; // return a reference to the element at index
		}
	}

	// Get number of elements in the vector
	int size() const
	{
		return length;
	}

	// Get the current capacity of the vector
	int capacity() const
	{
		return vCapacity;
	}

	// Display the elements of the vector
	void traverse() const
	{
		for (int i = 0; i < length; i++)
		{
			std::cout << arr[i] << std::endl;
		}
		std::cout << std::endl;
	}

	// Operator overloading for equality check
	bool operator==(Vector& other) const 
	{
		if (other.size() != length) 
		{
			return false;
		}
		else 
		{
			for (int i = 0; i < length; i++) 
			{
				if (arr[i] != other.at(i))
				{
					return false;
				}
			}
		}
		return true;
	};

	// Operator overloading for array-like access
	T& operator[](int i) 
	{
		if ((i < 0) || (i >= length)) 
		{
			std::cerr << std::endl << "Vector index out of bounds" << std::endl;
		}
		return at(i);
	}


	Vector& operator=(const Vector& source) 
	{
		// Do a self check.
		if (this == &source)
		{
			return *this;
		}
		// Reset self
		delete[] arr;
		arr = new T[1];
		vCapacity = 1;
		length = 0;
		for (int i = 0; i < source.size(); i++) 
		{
			push_back(source.at(i));
		}
		return *this;
	}

private:
	T* arr = new T[1]; // Pointer to an array of type t with inital size of 1
	int vCapacity = 1; // current capacity of the vector
	int length = 0; //current length (number of elements)

	// We have to address the “dynamic” aspects of this class.There are
	//	going to be times when we are working with a Vector object that
	//	we will need to expand the size of the vector.This happens in
	//	multiple places so we refactor that code out into its own method.
	// 
	// Make certain that you update the vCapacity and remember to set the class member to point at the new buffer.

	// Expand the size of the vector
	void expand(int newCapacity) 
	{
		if (newCapacity > vCapacity)
		{
			T* temp = new T[newCapacity]; // Allocate memory for a new array with the new capacity
			for (int i = 0; i < length; i++)
			{
				temp[i] = arr[i]; // Copy elements from the old array to the new array
			}
			delete[] arr; // Free the memory occupied by the old array
			vCapacity = newCapacity; // Update the capacity
			arr = temp; // Update the pointer to the new array
		}
		else 
		{
			std::cerr << "Vector::expand: new capacity is less than equal to current\n";
		}
	}


};




// Vector abstract data type will have  generic type t data values
// 
// Operations:
// put(T, index): Place data at the specified index push_back(T): Append data at the end of the vector 
// T at(index) : Get the element at the index
// int length() : Return the current length of the vector
// int capacity() : Returns the current capacity of the vector
// void traverse() : Traverse and print the vector(for now)
