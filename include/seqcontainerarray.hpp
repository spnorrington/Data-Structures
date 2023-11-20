#pragma once
#include "SeqContainer.hpp"

template <typename T>
class Vector : public SeqContainer<T>
{
public:
    Vector() : SeqContainer<T>() {}

    Vector(const Vector& obj) : SeqContainer<T>(obj) {}

    ~Vector() {}

    void put(T data, int index)
    {
        if (index == this->capacity())
        {
            this->push_back(data);
        }
        else
        {
            this->at(index) = data;
        }
    }

    void push_back(T data)
    {
        // if the number of elements is equal to capacity,
        // then we need to reallocate and deep copy
        if (this->size() == this->capacity())
        {
            this->expand(2 * this->capacity());
        }
        this->at(this->size()) = data;
        this->length++;
    }

    void traverse() const
    {
        for (int i = 0; i < this->size(); i++)
        {
            std::cout << this->at(i) << std::endl;
        }
        std::cout << std::endl;
    }

    bool operator==(const Vector& other) const
    {
        if (other.size() != this->size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < this->size(); i++)
            {
                if (this->at(i) != other.at(i))
                {
                    return false;
                }
            }
        }
        return true;
    }

    const T& operator[](int i) const
    {
        if (i < 0 || i >= this->size())
        {
            std::cerr << std::endl << "Vector index out of bounds" << std::endl;
        }
        return this->at(i);
    }

    Vector& operator=(const Vector& source)
    {
        // Do a self-check.
        if (this == &source)
        {
            return *this;
        }
        // Reset self
        this->clear();
        for (int i = 0; i < source.size(); i++)
        {
            this->push_back(source.at(i));
        }
        return *this;
    }
};

