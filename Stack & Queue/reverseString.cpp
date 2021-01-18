#include <bits/stdc++.h>

using namespace std;
// Reverse a string using Stack
char *reverse(char *S, int len)
{
    char *tmp = new char[len];
    stack<char> s;
    for (int i = 0; i < len; i++)
        s.push(S[i]);
    int i = 0;
    while (!s.empty())
    {
        tmp[i++] = s.top();
        s.pop();
    }
    tmp[i] = '\0';
    return tmp;
}

int main()
{
    char s[10000];
    cin >> s;
    long long n = strlen(s);
    char *ch = reverse(s, n);
    cout << ch;
}