

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

    T pop()
    {
        if (this->empty())
        {
            std::cerr << "Vector: pop() called on an empty vector" << std::endl;
            exit(1);
        }

        T lastElement = this->at(this->size() - 1);
        this->erase(this->end() - 1);
        return lastElement;
    }

    void traverse(void (*doIt)(T data)) const
    {
        for (auto it = this->begin(); it != this->end(); ++it)
        {
            doIt(*it);
        }
    }
};