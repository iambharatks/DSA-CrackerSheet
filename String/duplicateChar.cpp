#include <bits/stdc++.h>

using namespace std;

//48.Find Duplicate characters in string

int main()
{
    string s;
    cin >> s;
    int f[26] = {0};
    for (char i : s)
        f[i - 'a']++;
    for (int i = 0; i < 26; ++i)
        if (f[i] > 1)
            cout << char(i + 'a') << " " << f[i] << "\n";
}