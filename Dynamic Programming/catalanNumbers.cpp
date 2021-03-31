#include <bits/stdc++.h>

using namespace std;

//  Nth catalan number

class recursive
{
public:
    long long int findCatalan(int n)
    {
        if (n < 0)
            return 0;
        if (n == 0)
            return 1;
        long long c = 0;
        for (int i = 0; i < n; i++)
            c += findCatalan(i) * findCatalan(n - i - 1);
        return c;
    }
};
class memoization
{
public:
    long long int findCatalanUtil(int n, vector<long long int> &table)
    {
        if (n < 0)
            return 0;
        if (table[n] != -1)
            return table[n];
        long long c = 0;
        for (int i = 0; i < n; i++)
            c += findCatalanUtil(i, table) * findCatalanUtil(n - i - 1, table);
        return table[n] = c;
    }
    long long int findCatalan(int n)
    {
        vector<long long int> table(n + 1, -1);
        table[0] = 1;
        return findCatalanUtil(n, table);
    }
};

class tabulation
{
public:
    long long int findCatalan(int n)
    {
        vector<long long int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
int main()
{
    int n;
    cin >> n;
    cout << tabulation().findCatalan(n);
}
