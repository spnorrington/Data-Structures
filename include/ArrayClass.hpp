//
// File: ArrayClass.h
// 
// This program implements the Array template class, which is a wrapper around the base c++ array data type for cohesion and type safety. Having an Array class alongside the Vector class increases cohesion in the library. Additionally, the Array class enhances type safety by wrapping the base c++ array type in a class that can be used in the Vector class, which avoids the safety type issues with arrays.
// 
// The Array Template Class will use the same convention as the STL and parametrize the array class by the data type of the array. Public interface will be the same as the Vector class, including the array Index operator, except for some data from the vector class that is not valid for the array class.
// 
// 


#pragma once
#include <iostream>

template <typename T>
class Vector
{
public:
	Vector()
	{
		arr = new T[1];
		vCapacity = 1;
		length = 0;
	}
	Vector(const Vector& obj)
	{
		this->arr = new T[obj.capacity()];
		for (int i = 0; i < obj.size(); i++)
		{
			this->put(i, obj.at(i));
		}
	}
	~Vector()
	{
		delete[] arr;
		arr = nullptr;
	}

	void vector::put(T data, int index)
	{
		if (index == vCapacity)
		{
			push_back(T data);
		}
		else
		{
			arr[index] = data;
		}
	}

	void push_back(T data)
	{
		// if number of elements is equal to capacity
			// than we need to reallocate and deep copy
		if (length == vCapacity)
		{
			expand(2 * vCapacity);
		}
		arr[length] = data;
		length++;
	}

	T &at(int index)
	{
		if (index < 0 || index >= length)
		{
			std::cerr << "Vector: index out of bounds on access" << std::endl;
			exit(1);
		}
		else
		{
			return arr[index];
		}
	}

	int size() const
	{
		return length;
	}

	int capacity() const
	{
		return vCapacity;
	}

	void traverse() const
	{
		for (int i = 0; i < length; i++)
		{
			std::cout << arr[i] << std::endl;
		}
		std::cout << std::endl;
	}

	// Operator overloading
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

	// Overloading the array index operator
	// Overloading Operators gives us the ability to define things like equility, assignment, and comparison when needed. Holds for array indexes and function calls

	const T& operator[](int i) const
	{
		if ((i < 0) || (i >= length)) 
		{
			std::cerr << std::endl << "Vector index out of bounds" << std::endl;
		}
		return at(i);
	}

	//Vector(Vector& obj) {
 // Reset self
	//this->arr = new T[obj.capacity()];
	//for (int i = 0; i < obj.size(); i++) {
	//	this->put(i, obj.at(i)));


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
	T* arr = new T[1];
	int vCapacity = 1;
	int length = 0;

	// We have to address the “dynamic” aspects of this class.There are
	//	going to be times when we are working with a Vector object that
	//	we will need to expand the size of the vector.This happens in
	//	multiple places so we refactor that code out into its own method.
	// 
	// Make certain that you update the vCapacity and remember to set the class member to point at the new buffer.

	void expand(int newCapacity){
		if (newCapacity > vCapacity) 
		{
			T *temp = new T[newCapacity];
			for (int i = 0; i < length; i++) 
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			vCapacity = newCapacity;
			arr = temp;
		}
		else 
		{
			std::cerr << "Vector::expand: new capacity is less than equal to current\n";
		}
	}


};


template <typename T, size_t Size>
class Array 
{
public:
	Array() 
	{
		arr = default;
	}

	Array(const Array& obj) 
	{
		arr = new T[Size];
		for (size_t i = 0; i < Size; i++) 
		{
			arr[i] = obj.at(i);
		}
	}

	~Array()
	{
		delete[] arr;
		arr = nullptr;
	}

	const T& operator[](size_t i) 
	{
		if (i >= Size) {
			std::cerr << "Array index out of bounds" << std::endl;
			// Handle or exit appropriately
		}
		return arr[i];
	}

	const T& operator[](size_t i) const 
	{
		if (i >= Size) 
		{
			std::cerr << "Array index out of bounds" << std::endl;
			// Handle or exit appropriately
		}
		return arr[i];
	}

	// Other member functions similar to Vector that make sense for an Array

private:
	T* arr;
};

// Vector abstract data type will have  generic type t data values
// 
// Operations:
// put(T, index): Place data at the specified index push_back(T): Append data at the end of the vector 
// T at(index) : Get the element at the index
// int length() : Return the current length of the vector
// int capacity() : Returns the current capacity of the vector
// void traverse() : Traverse and print the vector(for now)
