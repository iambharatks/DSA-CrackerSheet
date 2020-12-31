#include <bits/stdc++.h>

using namespace std;
//54.Print all subsequences of a string
unordered_map<string, bool> mp;
void subsequences(string s, string ans = "")
{
    if (s.length() == 0)
    {
        if (!mp[ans])
            cout << ans << "\n";
        mp[ans] = true;
        return;
    }
    subsequences(s.substr(1), ans + s[0]);
    subsequences(s.substr(1), ans);
}

int main()
{
    string s;
    cin >> s;
    subsequences(s);
}