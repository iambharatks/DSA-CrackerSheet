#include <bits/stdc++.h>

using namespace std;

// Binomial Coefficient Problem

const int MOD = 1e9 + 7;

class recursive
{
public:
    int nCr(int n, int r)
    {
        if (n <= 0)
            return 0;
        if (r == 0 || r == n)
            return 1;
        return nCr(n - 1, r - 1) + nCr(n - 1, r);
    }
};
class memoization
{
public:
    int nCrUtil(int n, int r, vector<vector<int>> &table)
    {
        if (n <= 0)
            return 0;
        if (r == 0 || r == n)
            return 1;
        if (table[n][r] != -1)
            return table[n][r];
        return table[n][r] = (nCrUtil(n - 1, r - 1, table) + nCrUtil(n - 1, r, table)) % MOD;
    }
    int nCr(int n, int r)
    {
        vector<vector<int>> table(n + 1, vector<int>(r + 1, -1));
        return nCrUtil(n, r, table);
    }
};
class tabulation
{
public:
    int nCr(int n, int r)
    {
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                else if (j == 0 || i == j)
                    dp[i][j] = 1;
                else
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
            }
        }
        return dp[n][r];
    }
};
int main()
{
    int n, r;
    cin >> n >> r;
    cout << tabulation().nCr(n, r);
}