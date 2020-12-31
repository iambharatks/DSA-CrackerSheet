#include <bits/stdc++.h>

using namespace std;
//56.Split the binary string into substrings with equal number of 0s and 1s

int split(string s)
{
    int i = 0, n = s.size();
    int z = 0, cnt = 0;
    while (i < n)
    {
        if (s[i] == '0')
            z++;
        else
            z--;
        if (z == 0)
            ++cnt;
        ++i;
    }
    return (z == 0) ? cnt : -1;
}
int main()
{
    string s;
    cin >> s;
    cout << split(s);
}