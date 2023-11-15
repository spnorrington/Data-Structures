//
// File: hanoi.cpp
// #include <iostream>

#include <iostream>
#include <chrono>
#include <stack>
#include <cmath>

using namespace std;

void moveDisks(int, int, int, int);
void printIt(int , int , int );

int main() {
    const int FROMPEG = 1;
    const int TOPEG = 3;
    const int TEMPPEG = 2;
    const int NUMDISKS = 3;
    for (auto NUMDISKS: { 5, 10, 15, 20, 25, 30, 35 })
    {
      cout << "NUMDISKS: " << numdisks << endl;
      moveDisks(NUMDISKS, FROMPEG, TOPEG, TEMPPEG);
      cout << "Moved " << numdisks << " pegs"
           << " from peg " << FROMPEG
           << " to peg " << TOPEG << endl;
    }
}

void moveDisks(num, int fromPeg, int toPeg, int tempPeg) {
     if (num > 0) {
        moveDisks(num -1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg);
        moveDisks(num-1, tempPeg, toPeg, fromPeg);
     }
}

void printIt(int disk, int fromPeg, int toPeg) {
  // Do nothing for timing test, but otherwise
  cout<< "Move disk " << disk
      << " from pef " << fromPeg
      << " to peg " << toPeg << endl;
}
