#include <bits/stdc++.h>

using namespace std;
// Parenthesis Checker
bool parenthesisCheck(string expression)
{
    stack<char> s;
    for (char c : expression)
    {
        switch (c)
        {
        case '[':
        case '{':
        case '(':
            s.push(c);
            break;
        case ')':
            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{')
                return false;
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
            break;
        }
    }
    return s.empty();
}

int main()
{
    string s;
    cin >> s;
    if (parenthesisCheck(s))
        cout << "Is Balanced Expression\n";
    else
        cout << "Is not Balanced Expression\n";
}