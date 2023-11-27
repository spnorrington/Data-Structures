//
// File: hanoi.cpp
// This code is a recursive implementation of the Towers of Hanoi puzzle
// The starting code was provided by Professor Dr. Adam Lewis
// #include <iostream>

#include <iostream>
#include <chrono>

using namespace std;

void moveDisks(int, int, int, int);
void printIt(int, int, int);

int main() 
{
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 7;
    for (auto numdisks : { 5, 10, 15, 20, 25, 30, 35 })
    {

        cout << "Numdisks: " << numdisks << endl;
        auto start = std::chrono::steady_clock::now();
        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
        auto end = std::chrono::steady_clock::now();
        cout << "Moved " << numdisks << " pegs"
            << " from peg " << FROMPEG
            << " to peg " << TOPEG << endl;
        std::chrono::duration<double> elapsed_seconds = (end - start);
        cout << "Elapsed time: " << elapsed_seconds.count() << " seconds " << endl;

        cout << std::endl;
    }
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) 
{
    if (num == 0) // Modified to stop when num is 0 to prevent infinite loop
    {
        moveDisks(num - 1, fromPeg, tempPeg, toPeg);

        printIt(num, fromPeg, toPeg);


        moveDisks(num - 1, tempPeg, toPeg, fromPeg);
    }
}

void printIt(int disk, int fromPeg, int toPeg) 
{
    // Do nothing for timing test, but otherwise
    cout << "Move disk " << disk
        << " from pef " << fromPeg
        << " to peg " << toPeg << endl;
}

// Instructions:
// The starter code from Assignment 00 includes implementations of the Towers of Hanoi puzzle: a recursive implementation and an iterative implementation. In the lecture materials, we saw how to use the chrono library to determine how much time it took to compute the 
// -th Fibonacci number.There we noted that the iterative implementation was much faster.Using the code from the lecture as a guide(see the code in Your Glorious Instructor’s class GitHub repo), modify the main() functions in both versions of the Tower of Hanoi to compute how long it takes for 5, 10, 15, 20, 25, 30, and 35 disks.Do you see any difference in the timings between the recursive and iterative versions of the algorithm ?
//