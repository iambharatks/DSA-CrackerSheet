#include <bits/stdc++.h>

using namespace std;

// Coin Change Problem
//Maximum # of ways

class recursive
{
public:
    long long int count(vector<int> S, int m, int n)
    {
        //Base case
        if (n == 0)
            return 1;
        if (n < 0 || m <= 0)
            return 0;

        return count(S, m - 1, n) + count(S, m, n - S[m - 1]);
    }
};
class memoization
{
public:
    long long int countUtil(int S[], int m, int n, vector<vector<long long int>> &table)
    {
        //Base Case
        // cout << n << " " << m << "\n";
        if (n == 0)
            return 1;
        if (n < 0 || m <= 0)
            return 0;
        if (table[n][m - 1] != -1)
            return table[n][m - 1];
        long long int left = countUtil(S, m - 1, n, table);
        long long int right = countUtil(S, m, n - S[m - 1], table);
        return (table[n][m - 1] = left + right);
    }
    long long int count(int S[], int m, int n)
    {
        vector<vector<long long int>> table(n + 1, vector<long long int>(m, -1));
        countUtil(S, m, n, table);
        return table[n][m - 1];
    }
};
class Solution
{
public:
    long long int count(vector<int> S, int m, int n)
    {
        vector<vector<long long int>> table(n + 1, vector<long long int>(m));
        for (int i = 0; i < m; i++)
            table[0][i] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < m; j++)
            {
                long long int left = (i >= S[j]) ? table[i - S[j]][j] : 0;
                long long int right = (j >= 1) ? table[i][j - 1] : 0;
                table[i][j] = left + right;
            }
        }
        return table[n][m - 1];
    }
};
class Optimal
{
public:
    long long int count(vector<int> S, int m, int n)
    {
        vector<long long int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (j >= S[i])
                    dp[j] += dp[j - S[i]];
            }
        }
        return dp[n];
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> S(m);
    for (int &i : S)
        cin >> i;
    cout << Optimal().count(S, m, n);
}