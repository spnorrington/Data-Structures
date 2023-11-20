

#pragma once
#include "SeqContainer.hpp" // Include the header file for SeqContainer

template <typename T>
class SeqContainer; // Forward declaration

template <typename T>
class Vector : public SeqContainer<T>
{
public:
    Vector();
    Vector(const Vector& obj);
    ~Vector();

    void put(T data, int index);
    void push_back(T data);
    T& at(int index);

    int size() const; // Include missing method size()
    int capacity() const; // Include missing method capacity()
    void traverse() const; // Include missing method traverse()

    // Operator overloading
    bool operator==(Vector& other) const;
    T& operator[](int i);

    // Overloading the assignment operator
    Vector& operator=(const Vector& source);

private:
    // arr, vCapacity, and length declared in SeqContainer
};
