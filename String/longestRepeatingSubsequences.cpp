#include <bits/stdc++.h>

using namespace std;
//53.Longest Repeating Subsequence
int lpr(string s1, string s2)
{
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    //printing solution
    string lpr = "";
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1] && i != j)
        {
            lpr = s1[i - 1] + lpr;
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << lpr << " ";
    return dp[n][n];
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string s;
        cin >> s;
        cout << lpr(s, s) << "\n";
    }
}