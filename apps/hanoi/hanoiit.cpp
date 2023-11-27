//
/*
File: hanoiit.cpp
This code is an iterative implementation of the Towers of Hanoi puzzle
The purpose of this code is to compute how long 5, 10, 15, 20, 25, 30, and 35 disks compare the iterative and recursive implementations
*/
#include <iostream>
#include <chrono>
#include <stack>
#include <cmath>
using namespace std;

void moveDisks(int, stack<int> &, stack<int> &, stack<int> &);
void printIt(int, char, char);
void MoveDisksHelper(stack<int> &, stack<int> &, char, char);

int main() {
    for (auto numdisks : { 5, 10, 15, 20, 25, 30, 35 }) 
    {
        stack<int> source;
        stack<int> dest;
        stack<int> aux;
        cout << "Numdisks: " << numdisks << endl;
        auto start = std::chrono::steady_clock::now();
        moveDisks(numdisks, source, aux, dest);
        auto end = std::chrono::steady_clock::now();
        cout << "Moved " << numdisks << " pegs." << endl;
        std::chrono::duration<double> elapsed_seconds = (end - start);
        cout << "Elapsed time: " << elapsed_seconds.count() << " seconds " << endl;
    }
    return 0;
}

void moveDisks(int num, stack<int> &fromPeg, stack<int> &tempPeg, stack<int> &toPeg) 
{
    char s = 'S', d = 'D', a = 'A';
    if (num % 2 == 0) 
    { // Swap in num disks is even.
        char temp = d;
        d = a;
        a = temp;
    }
    int numberOfMoves = pow(2, num) - 1;
    for (int i = num; i >= 1; i--) 
    {
        fromPeg.push(i);
    }
    // now do moves:
    for (int i = 1; i <= numberOfMoves; i++) 
    {
        if (i % 3 == 0) 
        {
            MoveDisksHelper(tempPeg, toPeg, a, d);
        }
        else if (i % 3 == 2) {
            MoveDisksHelper(fromPeg, tempPeg, s, a);
        }
        else if (i % 3 == 1) {
            MoveDisksHelper(fromPeg, toPeg, s, d);
        }
    }
}

void MoveDisksHelper(stack<int>& source, stack<int>& dest, char s, char d) 
{
    int top1;
    int top2;
    if (source.empty()) 
    {
        top2 = dest.top();
        dest.pop();
        source.push(top2);
        //printIt(top2, d, s);
    }
    else if (dest.empty()) 
    {
        top1 = source.top();
        source.pop();
        dest.push(top1);
        //printIt(top1, s, d);
    }
    else if (source.top() > dest.top()) 
    {
        top1 = source.top();
        source.pop();
        top2 = dest.top();
        dest.pop();
        source.push(top1);
        source.push(top2);
        //printIt(top2, d, s);
    }
    else 
    {
        top2 = dest.top();
        dest.pop();
        top1 = source.top();
        source.pop();
        dest.push(top2);
        dest.push(top1);
        //printIt(top1, s, d);
    }
}

void printIt(int disk, char fromPeg, char toPeg) 
{
    // Do nothing for timing test, but otherwise
    std::cout << "Move disk " << disk
        << "from peg " << fromPeg
        << "to peg " << toPeg << std::endl;
}

//Instructions:
// The starter code from Assignment 00 includes implementations of the Towers of Hanoi puzzle: a recursive implementation and an iterative implementation. In the lecture materials, we saw how to use the chrono library to determine how much time it took to compute the 
// -th Fibonacci number.There we noted that the iterative implementation was much faster.Using the code from the lecture as a guide(see the code in Your Glorious Instructor’s class GitHub repo), modify the main() functions in both versions of the Tower of Hanoi to compute how long it takes for 5, 10, 15, 20, 25, 30, and 35 disks.Do you see any difference in the timings between the recursive and iterative versions of the algorithm ?
//
// Notes from class lecture ///
//
// 
//long fibit(int num) {
//    long x = 0, y = 1, z = 0;
//    for (int i = 0; i < num; i++) {
//        cout << x << " ";
//        z = x + y;
//        x = y;
//        y = z;
//    }
//    return z;
//}

//Note how much faster the iterative version is for this problem
//This is a result of the overhead of function calls in the recursive
//version
//
//
// <chrono> lib has three concepts: clocks, time points, and durations.
// clocks: epoch - start of time/ tick rate / system_clock as primary.
// time points: clocks have now() member function that returns a time passed since epoch.///time_point: represents amount of time since start of clock. ex time_point<system_clock> t = system_clock::now();
// 
// duration examples:
// std::chrono::duration<int, std::milli> d(10);
//d = std::chrono::milliseconds(5);
//d = std::chrono::seconds(10)
//
// References:
// Dr. Adam Lewis. "hanoitt.cpp" https://github.com/adamwadelewis/cs372.lewis.fa23/blob/main/apps/hanoi/hanoiit.cpp