
// 
// 
//The Josephus problem is the following game: N people,  numbered 1 to N, are sitting in a circle. Starting at person 1, a hot  potato is passed. After M passes, the person holding the hot potato  is eliminated, the circle closes ranks, and the game continues with  the person who was sitting after the eliminated person picking up the  hot potato. The last remaining person wins.

//Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins.If M = 1 and N = 5, the order of elimination is 2, 4, 1, 5.  Write a program that solves the Josephus problem for any input values of M and N.Try  to make your program as efficient as possible if you used a a list, stack, or queue in this problem.

//File Name: hotpotato.cpp


#include <iostream>
#include <cmath>
#include "CircularList.hpp"




int main() 
{
    int numberOfPeople;
    int numberOfPasses;

    std::cout << "Enter the number of people: ";
    std::cin >> numberOfPeople;
    std::cout << "Enter the elimination interval: ";
    std::cin >> numberOfPasses;

    CircularList<int> circle;

    // Initialize circular list
    for (int i = 1; i <= numberOfPeople; ++i) 
    {
        circle.push_back(i);
    }

    typename CircularList<int>::iterator it = circle.begin();

    //  Elimation loop
    while (circle.size() > 1) {
        for (int i = 1; i < numberOfPasses; ++i) 
        {
            ++it;
        }

        // Eliminate the person at 'it'
        it = circle.erase(it);
    }

    // Prints the last person standing in the circle
    std::cout << "The last person standing is: " << circle.front() << std::endl;

    return 0;
}
}
