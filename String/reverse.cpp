#include <bits/stdc++.h>

using namespace std;

//46.Reverse a string
void reverse(string &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
        swap(s[l++], s[r--]);
}
int main()
{
    string s;
    cin >> s;
    reverse(s);
    cout << s;
}