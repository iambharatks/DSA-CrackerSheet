#include <bits/stdc++.h>

using namespace std;

int evaluate(int a, int b, char op)
{
    switch (op)
    {
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    }
    return INT_MIN;
}

int evaluatePostfix(string postfix)
{
    stack<int> operand;
    for (char c : postfix)
    {
        if (c >= '0' && c <= '9')
            operand.push(c - '0');
        else
        {
            int op1 = operand.top();
            operand.pop();
            int op2 = operand.top();
            operand.pop();
            int soln = evaluate(op2, op1, c);
            cout << op2 << " " << c << " " << op1 << " = " << soln << "\n";
            operand.push(soln);
        }
    }
    return operand.top();
}

int main()
{
    string s;
    cin >> s;
    cout << evaluatePostfix(s);
}