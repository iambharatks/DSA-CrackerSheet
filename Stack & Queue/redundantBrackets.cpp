#include <bits/stdc++.h>

using namespace std;

// using stack we see whether
// there are opernades bw every pair of brackets
// if there is no operand bw any pair its redundant pair of brackets
//Time complexity := O(n)
//Space complexity := O(n)
bool hasRedundantBrackets(string s)
{
    stack<char> bracks;
    int curCnt = 0;
    int maxCnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            bracks.push(i);
        else if (s[i] == ')')
        {
            char top = bracks.top();
            bracks.pop();
            bool isRedundant = true;
            while (s[top] != '(')
            {
                top = bracks.top();
                bracks.pop();
                isRedundant = false;
            }
            if (isRedundant)
                return true;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            bracks.push(i);
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    if (hasRedundantBrackets(s))
        cout << "Yes\n";
    else
        cout << "No\n";
}