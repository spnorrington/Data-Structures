
// 
// 
//The Josephus problem is the following game: N people,  numbered 1 to N, are sitting in a circle. Starting at person 1, a hot  potato is passed. After M passes, the person holding the hot potato  is eliminated, the circle closes ranks, and the game continues with  the person who was sitting after the eliminated person picking up the  hot potato. The last remaining person wins.

//Thus, if M = 0 and N = 5, players are eliminated in order, and player 5 wins.If M = 1 and N = 5, the order of elimination is 2, 4, 1, 5.  Write a program that solves the Josephus problem for any input values of M and N.Try  to make your program as efficient as possible if you used a a list, stack, or queue in this problem.



#include <iostream>
#include "List.h" 
#include "Circularlist.hpp"

int josephus(int N, int M);

int main() {
    int N, M;
    std::cout << "Enter the number of people (N): ";
    std::cin >> N;
    std::cout << "Enter the elimination interval (M): ";
    std::cin >> M;

    int winner = josephus(N, M);

    std::cout << "The winner is person " << winner << std::endl;

    return 0;
}

int josephus(int N, int M) {
    CircularList<int> circle;

    // Populate the circular list with values from 1 to N
    for (int i = 1; i <= N; ++i) {
        circle.push_back(i);
    }

    typename CircularList<int>::iterator current = circle.begin();

    // Simulate the elimination process
    while (N > 1) {
        for (int i = 0; i < M; ++i) {
            ++current;
            if (current == circle.end()) {
                current = circle.begin();
            }
        }

        // Eliminate the current person
        typename CircularList<int>::iterator next = current;
        ++next;

        if (next == circle.end()) {
            next = circle.begin();
        }

        circle.erase(current);
        current = next;

        --N;
    }

    // The last remaining person is the winner
    return circle.front();
}

	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started: 
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file