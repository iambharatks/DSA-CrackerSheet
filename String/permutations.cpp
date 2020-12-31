#include <bits/stdc++.h>

using namespace std;
//55.Permutations of a given string
void permute(string s, int idx = 0)
{
    if (idx == s.size())
    {
        cout << s << "\n";
        return;
    }
    for (int i = idx; i < s.size(); ++i)
    {
        if (i != idx && s[i] == s[idx])
            continue;
        swap(s[i], s[idx]);
        permute(s, idx + 1);
        swap(s[i], s[idx]);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        permute(s);
    }
}