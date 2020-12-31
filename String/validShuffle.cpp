#include <bits/stdc++.h>

using namespace std;
//50.Check if a string is a valid shuffle of two distinct strings

//if a and b donot have equal characters
bool isInterleaving(string a, string b, string c)
{
    int A = 0, B = 0;
    for (int C = 0; C < c.size(); C++)
    {
        if (A < a.size() && c[C] == a[A])
            A++;
        else if (B < b.size() && c[C] == b[B])
            B++;
        else
            return false;
    }
    if (A < a.size() || B < b.size())
        return false;
    return true;
}
//if a and b may have same characters
// Time := O(2^(m+n))
bool check(string a, string b, string c, int A, int B, int C)
{
    if (A >= a.size() && B >= b.size() && C >= c.size())
        return true;
    if (C >= c.size())
        return false;
    return ((a[A] == c[C] && check(a, b, c, A + 1, B, C + 1)) || (b[B] == c[C] && check(a, b, c, A, B + 1, C + 1)));
}
//Time: O(m*n)
//Space : O(m*n)
bool dynamic(string a, string b, string c)
{
    int n = a.size(), m = b.size();
    bool dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    if (m + n != c.size())
        return false;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (j == 0)
            {
                if (a[i - 1] == c[i - 1])
                    dp[i][j] = dp[i - 1][j];
            }
            else if (i == 0)
            {
                if (b[j - 1] == c[j - 1])
                    dp[i][j] = dp[i][j - 1];
            }
            else if (a[i - 1] != c[i + j - 1] && b[j - 1] == c[i + j - 1])
                dp[i][j] = dp[i][j - 1];
            else if (a[i - 1] == c[i + j - 1] && b[j - 1] != c[i + j - 1])
                dp[i][j] = dp[i - 1][j];
            else if (a[i - 1] == c[i + j - 1] && b[j - 1] == c[i + j - 1])
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    return dp[n][m];
}
int main()
{
    string s1, s2, res;
    cin >> s1 >> s2 >> res;
    if (dynamic(s1, s2, res))
        cout << res << " is interleaving \n";
    else
        cout << res << " is not interleaving \n";
}