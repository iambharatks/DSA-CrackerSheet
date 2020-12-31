#include <bits/stdc++.h>

using namespace std;
//58.Edit Distance

//Recursion And Backtracking
int editDist(int i, int j, string s1, string s2)
{
    if (i == s1.size())
        return s2.size() - j;
    if (j == s2.size())
        return s1.size() - i;

    if (s1[i] == s2[j])
        return editDist(i + 1, j + 1, s1, s2);

    int add = 1 + editDist(i, j + 1, s1, s2);
    int remove = 1 + editDist(i + 1, j, s1, s2);
    int replace = 1 + editDist(i + 1, j + 1, s1, s2);
    return min(add, min(remove, replace));
}
//Dynamic Programing
//Bottom Up
int editDistance(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    //Initilization:
    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= m; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
            dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
    }
    return dp[n][m];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string s1, s2;
        cin >> s1 >> s2;
        cout << editDistance(s1, s2) << "\n";
    }
}