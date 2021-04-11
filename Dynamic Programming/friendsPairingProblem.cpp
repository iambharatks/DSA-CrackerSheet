#include <bits/stdc++.h>

using namespace std;

// Friends Pairing Problem 

const int MOD = 1e9 + 7;
typedef long long ll;

class recursion
{
public:
    int countFriendsPairings(int n)
    {
        if (n <= 1)
            return 1;
        return countFriendsPairings(n - 1) + (n - 1) * countFriendsPairings(n - 2);
    }
};
class memoization
{
    vector<ll> table;

public:
    ll countFriendsPairingsUtil(int n)
    {
        if (table[n] != -1)
            return table[n];
        return table[n] = (countFriendsPairingsUtil(n - 1) + ((n - 1) * countFriendsPairingsUtil(n - 2))) % MOD;
    }
    ll countFriendsPairings(int n)
    {
        table.resize(n + 1, -1);
        table[0] = table[1] = 1;
        return countFriendsPairingsUtil(n);
    }
};

class tabulation
{
public:
    ll countFriendsPairings(int n)
    {

        vector<ll> dp(n + 1, 0);
        dp[1] = dp[0] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + ((i - 1) * dp[i - 2])) % MOD;
        return dp[n];
    }
};
class Solution
{
public:
    ll countFriendsPairings(int n)
    {
        ll a = 1, b = 1, c;
        for (int i = 2; i <= n; i++)
        {
            c = (b + (i - 1) * a) % MOD;
            a = b % MOD;
            b = c;
        }
        return c;
    }
};

int main()
{
    int n;
    cin >> n;
    cout << Solution().countFriendsPairings(n);
}