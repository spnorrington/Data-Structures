// This program is a calculator that accepts a fully parenthesized expression as input and outputs the expression in both prefix and postfix notation.
// Using the stack class in the solution







#include <iostream>
#include <cctype>     // Provides isdigit()
#include <cstring>    // For strchr()
#include <stack>      // Let's use the STL stack
#include <sstream>    // For istringstream

using namespace std;
bool isBalanced(const string &express);
double readAndEvaluate(const string &express, char notation);
void evaluateStackTops(stack<double>& numbers, stack<char>& operations, char notation);

int main() 
{
    string express;
    char notation;

    cout << "Type a fully parenthsized expression" << endl;
    getline(cin, express);

    // Check if parentheses are balanced before proceeding
    if (!isBalanced(expression)) 
    {
        cout << "Error: Unbalanced parentheses!" << endl;
        return 1; // Exit with an error code
    }
    cout << "Enter 'p' to see the prefix form, " << endl;
    cout << "      'i' to see the infix form, " << endl;
    cout << "   or 't' to see the postfix form: ";
    double answer = readAndEvaluate(express, notation);
    cout << "That evaluates to " << answer << endl;


    return 0;
}


// Function to check if parentheses are balanced
bool isBalanced(const string& express) 
{
    const char LEFTPAREN = '(';
    const char RIGHTPAREN = ')';
    stack<char> store;
    string::size_type  placeInString;
    char next;
    bool failed = false;
    for (i = 0; !failed && (placeInString < express.length); ++i) 
    {
        next = express[i];
        if (next == LEFTPAREN) 
        {
            store.push(next);
        }
        else if ((next == RIGHTPAREN) && !store.empty()) 
        {
            store.pop();
        }
        else if ((next == RIGHTPAREN) && store.empty()) 
        {
            failed = true;
        }
    }
    return (store.empty() && !failed);
}


// Function to read and evaluate an arithmetic expression
double readAndEvaluate(const string& express, char notation)
{
    const char DECIMAL = '.';
    const char RIGHTPAREN = ')';
    stack<double> numbers;
    stack<char> operations;
    double number;
    char symbol;

    istringstream ins(express);

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
            
            // Prefix notation option
            if (notation == 'p') 
			{
				evaluateStackTops(numbers, operations, notation);
			}
            operations.push(symbol);

            // Postfix notation option
            if (notation == 't')
            {
                evaluateStackTops(numbers, operations, notation);
            }
        }
        else if (ins.peek() == RIGHTPAREN) 
        {
            ins.ignore();
            evaluateStackTops(numbers, operations, notation);
        }
        else 
        {
            ins.ignore();
        }
        // Process any remaining operators
        while (!operations.empty()) 
        {
            evaluateStackTops(numbers, operations, notation);
        }

    }
    return numbers.top();
}
void evaluateStackTops(stack<double>& numbers, stack<char>& operations, char notation
{
        double op1, op2;
        // Evaluate an operator by applying it to the two operands

// Prefix notation option
        if (notation != 'p')
        {
        op2 = numbers.top();
        numbers.pop();
        op1 = numbers.top();
        numbers.pop();
		}

        // Postfix notation option
        else 
        {
            op1 = numbers.top();
            numbers.pop();
            op2 = numbers.top();
            numbers.pop();
        }

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