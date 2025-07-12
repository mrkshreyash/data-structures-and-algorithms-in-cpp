#include <iostream>
#include <stack>

using namespace std;

// Helper function to check the opening and closing symbols
bool isMatchingPair(char opening, char closing)
{
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

// Function to check if the expression is balanced or not
bool isBalanced(string expression)
{
    stack<char> expStack;

    for (char ch : expression)
    {
        // If opening symbol, push to stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            expStack.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == ']')
        {
            if (expStack.empty() || !isMatchingPair(expStack.top(), ch))
            {
                return false; // Mismatch found or stack is emtpy.
            }
            expStack.pop(); // Pop the matched opening symbol
        }
    }

    // If stack is empty, then all symbols are matched already.
    return expStack.empty();
}

int main()
{
    string expression;

    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "The expression is balanced." << endl;
    else
        cout << "The expression is not balanced." << endl;

    return 0;
}