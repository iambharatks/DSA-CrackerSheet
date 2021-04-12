#include <bits/stdc++.h>

using namespace std;

// Painting the Fence 


class tabulation
{
    const int MOD = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        vector<long long> dp(n + 1, 0);
        dp[1] = k;
        dp[2] = k * k;
        for (int i = 3; i <= n; i++)
            dp[i] = ((k - 1) * (dp[i - 1] + dp[i - 2])) % MOD;
        return dp[n];
    }
};

class Optimal
{
    const int MOD = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        long long a = k, b = k * k, c = 0;
        if (n == 1)
            return a;
        if (n == 2)
            return b;
        for (int i = 3; i <= n; i++)
        {
            c = ((k - 1) * (a + b)) % MOD;
            a = b;
            b = c;
        }
        return c;
    }
};

class Solution
{

    const int MOD = 1e9 + 7;

public:
    long long countWays(int n, int k)
    {
        long long same = 0, diff = k, total = same + diff;
        for (int i = 2; i <= n; i++)
        {
            same = diff;
            diff = total * (k - 1);
            total = (same + diff) % MOD;
        }
        return total;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    cout << Solution().countWays(n, k);
}