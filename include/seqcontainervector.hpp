

#pragma once
#include "SeqContainer.hpp" // Include the header file for SeqContainer

template <typename T>
class Vector : public SeqContainer<T>
{
public:
    Vector() : SeqContainer<T>() {}
    Vector(const Vector& obj) : SeqContainer<T>(obj) {}
    ~Vector() {}
    bool empty() const { return this->size() == 0; }
    void push(T data) { this->push_back(data); }
    T front() { return queueList.front(); }
    T back() { return queueList.back(); }
    void pop() { this->pop_back(); }

};