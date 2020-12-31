#include <bits/stdc++.h>

using namespace std;

//47.Check Palindrome
bool isPalindrome(string &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
        if (s[l++] != s[r--])
            return false;
    return true;
}
int main()
{
    string s;
    cin >> s;
    if (isPalindrome(s))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
}