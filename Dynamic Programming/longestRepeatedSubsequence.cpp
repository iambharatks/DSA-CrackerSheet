#include <bits/stdc++.h>

using namespace std;

class recursion
{
public:
    int LongestRepeatingSubsequenceUtil(string s, int i, int j)
    {
        if (i >= s.size() || j > s.size())
            return 0;
        if (i != j && s[i - 1] == s[j - 1])
            return LongestRepeatingSubsequenceUtil(s, i + 1, j + 1) + 1;
        return max(LongestRepeatingSubsequenceUtil(s, i + 1, j), LongestRepeatingSubsequenceUtil(s, i, j + 1));
    }
    int LongestRepeatingSubsequence(string s)
    {
        return LongestRepeatingSubsequenceUtil(s, 0, 0);
    }
};

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        size_t n = str.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && str[i - 1] == str[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
};

int main()
{
    string s;
    cin >> s;
    cout << recursion().LongestRepeatingSubsequence(s);
}