#include <bits/stdc++.h>

using namespace std;

//60.Parenthesis Checker
bool isPar(string str)
{
    stack<char> s;
    for (char i : str)
    {
        switch (i)
        {
        case '{':
        case '(':
        case '[':
            s.push(i);
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
    cout << isPar(s);
}