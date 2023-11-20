//
//  Note
// This is a sample test provided by Professor Dr Adam Lewis
// https://github.com/adamwadelewis/cs372.lewis.fa23/blob/main/apps/stlvectest/stlvectest.cpp
// with minimal modification.
// This program will be used to test my implementation of the vector class
// 

#include "vector.hpp"
#include <chrono>
#include <iostream>

const int PrintInterval = 10;

class VecTester {
private:
    Vector<int> testVector = Vector<int>();

public:
    void tester() 
    {
        size_t currentCap = testVector.capacity();
        std::cout << "Starting capacity: " << currentCap << std::endl;

        for (int i = 0; i <= 500; i++) {
            if ((i % PrintInterval) == 0) {
                std::cout << "Current cap: " << currentCap << std::endl;
            }
            
            testVector.push_back(i);
            currentCap = testVector.capacity();

            if ((i % PrintInterval) == 0) {
                std::cout << "Increased capacity to "
                    << currentCap
                    << std::endl;
            }
        }
    }
};

int main() 
{
    VecTester testingObject;
    std::cout << "Starting test: " << std::endl;
    testingObject.tester();
    return 0;
}