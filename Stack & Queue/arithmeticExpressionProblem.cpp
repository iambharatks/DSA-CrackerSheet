#include <bits/stdc++.h>

using namespace std;

// Arithmetic Expression Evalution
int solve(string s)
{
    stack<char> operators;
    stack<int> operands;
    for (char c : s)
    {
        if (c == '(')
            operators.push(c);
        else if (c == ')')
            operators.pop();
        else
        {
            if (s.size() > 1)
            {
                int a = operands.top();
                operands.pop();
                int b = operands.top();
                operands.pop();
                switch (operators.top())
                {
                case '+':
                    operators.push(b + a);
                    break;
                case '-':
                    operators.push(b - a);
                    break;
                case '*':
                    operators.push(b * a);
                    break;
                case '/':
                    if (a == 0)
                    {
                        cout << "Zero division error\n";
                        return operands.top();
                    }
                    operators.push(b / a);
                    break;
                case '^':
                    operators.push(pow(b, a));
                    break;
                default:
                    cout << "Invalid operator\n";
                    return operands.top();
                }
            }
        }
    }
    return operands.top();
}

int main()
{
    string s;
    cin >> s;
    cout << solve(s);
}