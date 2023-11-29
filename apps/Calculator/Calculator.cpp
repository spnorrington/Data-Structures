
// File: Calculator.cpp
// -----------  INSTRUCTIONS ---------------------
// In lecture, we did a case study that illustrated how to use a pair of stacks to implement a simple calculator that is capable of evaluating a fully parenthesized expression.  Use that code as a guide to implement a program that accepts a fully parenthesized expression as input and outputs the expression in both prefix and postfix notation. 


// You may use the `Stack` class from the previous question or the STL's `stack` class in your solution.  (HINT: Most of the work is done for you already, look closely at how the simple calculator does manipulation of the stacks.)


#include <iostream>
#include <cctype>     // Provides isdigit()
#include <cstring>    // For strchr()
#include <stack>      // Let's use the STL stack
#include <sstream> // Added for stringstream

using namespace std;

// Function to read and evaluate a fully parenthesized expression
double readAndEvaluate(istream& ins);

// Function to evaluate the tops of the stacks (numbers and operations)
void evaluateStackTops(stack<double>& numbers,
    stack<char>& ops);

int main() 
{
    cout << "This program evaluates fully parenthesized expressions" << endl; 
    cout << "Input the fully parenthesized expression, and the program will output the expression in both prefix and post fix notation." << endl;

    cout << "Type a fully parenthsized expression" << endl;
    double answer;
    string infixExpression, postfixExpression, prefixExpression;
    // Call the readAndEvaluate function to perform the evaluation

    answer = readAndEvaluate(cin, infixExpression, postfixExpression, prefixExpression);

    cout << "That evaluates to " << answer << endl;
    return 0;
}


// Function to read and evaluate a fully parenthesized expression
double readAndEvaluate(istream& ins) 
{
    const char DECIMAL = '.';
    const char RIGHTPAREN = ')';
    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;

    // Initializing expressions 
    infixExpression = "";
    postfixExpression = "";
    prefixExpression = "";


    while (ins && ins.peek() != '\n') 
    {
        if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) 
        {
            ins >> number;
            numbers.push(number);
            // Track the postfix expression
            postfixExpression += to_string(number) + " ";
            // Track the prefix expression
            prefixExpression = to_string(number) + " " + prefixExpression;
        }
        else if (strchr("+-*/", ins.peek()) != NULL) 
        {
            ins >> symbol;
            operations.push(symbol);
            // Track the postfix expression
            postfixExpression += symbol;
            // Track the prefix expression
            prefixExpression = symbol + " " + prefixExpression;
        }
        else if (ins.peek() == RIGHTPAREN) 
        {
            ins.ignore();
            evaluateStackTops(numbers, operations);
            // Track the postfix expression
            postfixExpression += " ";

        }
        else 
        {
            ins.ignore();
        }
    }
    return numbers.top();
}


// Function to evaluate the tops of the stacks (numbers and operations)
void evaluateStackTops(stack<double)& numbers,
    stack<char>& operations) 
    {
        double op1, op2;
        op2 = numbers.top();
        numbers.pop();
        op1 = numbers.top();
        numbers.pop();

        // Perform the arithmetic operation
        switch (operations.top())
        {
        case '+': numbers.push(op1 + op2);
            break;
        case '-': numbers.push(op1 - op2);
            break;
        case '*': numbers.push(op1 * op2);
            break;
        case '/': numbers.push(op1 / op2);
            break;
        }
        operations.pop();

        }



// ------------ Notes -------------------
/*  The source code(Orginal code) implements a simple arithmetic expression evaluation for fully parenthesized expressions in infix notation
    It uses two stacks: One for numbers and One for operators. These stacks process and evaluate the expression. 
    The main function prompts the user to enter an expression, calls the evaluation function, and then displays the result.The evaluation involves handling digits, operators, and parentheses, following the rules of arithmetic expressions.

    Need to modify the program to output the pre fix and post fix notation of the expression. I am going to be including the infix notation as well for reference and testing purposes.

 Infix: ((((12 + 9) / 3) + 7.2)*((6 - 4) /8 )
 Postfix: 12 9 + 3 / 7.2 + 6 4 - 8 / *
 Prefix: * / + 12 9 3 + 7.2 / - 6 4 8

 "Not only can a stack be used to evaluate a postfix expression, but we can also use a stack to convert an expression in standard form (otherwise known as infix) into postfix. We will concentrate on a small version of the general problem by allowing only the operators +, *, (,), and insisting on the usual precedence rules. We will further assume that the expression is legal. Suppose we want to convert the infix expression
a + b * c + ( d * e + f ) * g
into postfix. A correct answer is a b c * + d e * f + g * +."
*/