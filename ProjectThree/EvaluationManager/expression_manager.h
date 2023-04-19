#ifndef EXPRESSION_MANAGER_H_INCLUDED
#define EXPRESSION_MANAGER_H_INCLUDED

#pragma once

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Returns true if the character is an operand
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Returns the precedence of an operator
int getOperatorPrecedence(string op) {
    if (op == "*" || op == "/" || op == "%") {
        return 2;
    } else if (op == "+" || op == "-") {
        return 1;
    } else {
        return 0;
    }
}

// Converts an infix expression to postfix notation
string infixToPostfixConversion(string exp) {
    string postfix = "";
    stack<char> s;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ') {
            continue; // Ignore whitespace
        }
        else if (isOperand(exp[i])) {
            postfix += exp[i];
        }
        else if (exp[i] == '(') {
            s.push(exp[i]);
        }
        else if (exp[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() != '(') {
                return "Invalid Expression"; // Mismatched parenthesis
            }
            else {
                s.pop();
            }
        }
        else { // Operator
            while (!s.empty() && getOperatorPrecedence(string(1, exp[i])) <= getOperatorPrecedence(string(1, s.top()))) {
                postfix += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Checks whether an expression has balanced parentheses
bool isParenthesesBalanced(string exp) {
    stack<char> s;
    for (size_t i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.empty();
}

#endif // EXPRESSION_H_INCLUDED
