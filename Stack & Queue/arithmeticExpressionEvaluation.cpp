#include <bits/stdc++.h>

using namespace std;

//evaluating infix expression for single digit operands

//Method 1 would be directly solve infix
//Method 2 would be convert it into postfix and then evaluate

//I solved using Method 1
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

int operations(int a, int b, char op)
{
    switch (op)
    {
    case '^':
        return pow(a, b);
    case '*':
        return a * b;
    case '/':
        if (b == 0)
            return INT_MIN;
        return a / b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    }
    return INT_MAX;
}
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int solve(string infix)
{
    stack<int> operand;
    stack<char> op;
    for (char c : infix)
    {
        if (c >= '0' && c <= '9')
            operand.push(c - '0');
        else if (c == '(')
            op.push(c);
        else if (c == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                char oper = op.top();
                op.pop();
                int op1 = operand.top();
                operand.pop();
                int op2 = operand.top();
                operand.pop();
                int soln = operations(op2, op1, oper);
                if (soln == INT_MAX)
                    return 0;
                cout << op2 << " " << oper << " " << op1 << " = " << soln << "\n";
                operand.push(soln);
            }
            if (op.empty())
                return INT_MAX;
            op.pop();
        }
        else
        {
            if (op.empty() || op.top() == '(' || precedence(c) > precedence(op.top()))
                op.push(c);
            else
            {
                while (!op.empty() && op.top() != '(' && precedence(c) <= precedence(op.top()))
                {

                    char oper = op.top();
                    op.pop();
                    int op1 = operand.top();
                    operand.pop();
                    int op2 = operand.top();
                    operand.pop();
                    int soln = operations(op2, op1, oper);
                    if (soln == INT_MAX)
                        return 0;
                    cout << op2 << " " << oper << " " << op1 << " = " << soln << "\n";
                    operand.push(soln);
                }
                op.push(c);
            }
        }
    }
    while (!op.empty())
    {
        char oper = op.top();
        op.pop();
        int op1 = operand.top();
        operand.pop();
        int op2 = operand.top();
        operand.pop();
        int soln = operations(op2, op1, oper);
        if (soln == INT_MAX)
            return 0;
        cout << op2 << " " << oper << " " << op1 << " = " << soln << "\n";
        operand.push(soln);
    }
    return operand.top();
}

int main()
{
    string infix;
    cin >> infix;
    cout << solve(infix);
}