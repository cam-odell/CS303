#include <iostream>
#include "expression_manager.h"

using namespace std;

int main() {
    // Prompt user to enter an infix expression
    string exp;
    cout << "Enter an infix expression: ";
    getline(cin, exp);

    // Check if parentheses is balanced
    if (!isParenthesesBalanced(exp)) {
        cout << "Expression is not balanced \n";
        return 0;
    }

    // Convert expression to postfix and display result
    string postfix = infixToPostfixConversion(exp);
    cout << "Postfix expression is:" << postfix << endl;

    return 0;
}
