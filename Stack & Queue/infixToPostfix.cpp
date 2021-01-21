#include <bits/stdc++.h>

using namespace std;

int precedence(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    }
    return -1;
}

//Infix to postfix
string infixToPostfix(string infix)
{
    stack<char> operators;
    string postfix = "";
    for (char c : infix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            postfix += c;
        else if (c == '(')
            operators.push(c);
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            if (operators.empty())
                return "Invalid infix expression";
            operators.pop();
        }
        else
        {
            if (operators.empty() || operators.top() == '(' || precedence(c) > precedence(operators.top()))
                operators.push(c);
            else
            {
                while (!operators.empty() && operators.top() != '(' && precedence(c) <= precedence(operators.top()))
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }
    }
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cin >> infix;
    cout << infixToPostfix(infix);
}