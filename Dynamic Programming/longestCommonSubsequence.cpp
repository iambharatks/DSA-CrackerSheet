#include <bits/stdc++.h>

using namespace std;

// Longest Common Subsequence 

class recursion
{
    int maxim(int a, int b, int c) { return max(a, max(b, c)); }

public:
    int lcs(int x, int y, string s1, string s2)
    {
        if (x <= 0 || y <= 0)
            return 0;
        if (s1[x - 1] == s2[y - 1])
            return lcs(x - 1, y - 1, s1, s2) + 1;
        return maxim(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2), lcs(x - 1, y - 1, s1, s2));
    }
};

class Solution
{
    int maxim(int a, int b, int c) { return max(a, max(b, c)); }

public:
    int lcs(int x, int y, string s1, string s2)
    {
        // int val = 0;
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        for (int i = 0; i < x; i++)
            dp[i][0] = 0;
        for (int i = 0; i < y; i++)
            dp[0][i] = 0;
        // cout << "Longest Common Subsequence is";
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                // cout << dp[i][j] << " ";
                // if (val < dp[i][j])
                // {
                //     cout << s1[i - 1];
                //     val = dp[i][j];
                // }
            }
        }
        cout << '\n';
        return dp[x][y];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    cout << Solution().lcs(n, m, s1, s2);
}