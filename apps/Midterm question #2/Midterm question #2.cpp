// File: Midterm question #2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Using either the STL stack class or your own Stack class, write a small program that, given a string input by the user from the keyboard, will tell the user whether or not the string contains a matching number of parentheses.

#include <iostream>
#include <string>
#include <stack>



int main() 
{
    std::string input;
    std::cout << "Please enter a string input: ";
    std::cin >> input;
    std::stack<char> parentheseStack;

    for (int i = 0; i < input.length(); i++) 
    {
        if (input[i] == '(') 
        {
            parentheseStack.push(input[i]);
        }
        else if (input[i] == ')') {
            if (parentheseStack.empty()) 
            {
                std::cout << "The string does not contain a matching number of parentheses." << std::endl;
                return 0;
            }
            else {
                parentheseStack.pop();
            }
        }
    }

    if (parentheseStack.empty()) 
    {
        std::cout << "The string contains a matching number of parentheses." << std::endl;
    }
    else 
    {
        std::cout << "The string does not contain a matching number of parentheses." << std::endl;
    }

    return 0;
}







