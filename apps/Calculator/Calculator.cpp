// This program is a calculator that accepts a fully parenthesized expression as input and outputs the expression in both prefix and postfix notation.
// Using the stack class in the solution







#include <iostream>
#include <cctype>     // Provides isdigit()
#include <cstring>    // For strchr()
#include <stack>      // Let's use the STL stack

using namespace std;
double readAndEvaluate(istream& ins);
void evaluateStackTops(stack<double>& numbers,stack<char>& ops);

int main() 
{
    string express;
    char notation;

    cout << "Type a fully parenthsized expression" << endl;
    getline(cin, express);

    cout << "Enter 'p' to see the prefix form, " << endl;
    cout << "      'i' to see the infix form, " << endl;
    cout << "   or 't' to see the postfix form: ";
    double answer = readAndEvaluate(express, notation);
    cout << "That evaluates to " << answer << endl;
    return 0;
}
double readAndEvaluate(istream& ins) 
{
    const char DECIMAL = '.';
    const char RIGHTPAREN = ')';
    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;
    while (ins && ins.peek() != '\n') 
    {
        if (isdigit(ins.peek()) || (ins.peek() == DECIMAL)) 
        {
            ins >> number;
            numbers.push(number);
        }
        else if (strchr("+-*/", ins.peek()) != NULL) 
        {
            ins >> symbol;
            operations.push(symbol);
        }
        else if (ins.peek() == RIGHTPAREN) 
        {
            ins.ignore();
            evaluateStackTops(numbers, operations);
        }
        else 
        {
            ins.ignore();
        }
    }
    return numbers.top();
}
void evaluateStackTops(stack<double>& numbers, stack<char>& operations) 
{
        double op1, op2;
        op2 = numbers.top();
        numbers.pop();
        op1 = numbers.top();
        numbers.pop();
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