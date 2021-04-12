#include <bits/stdc++.h>

using namespace std;

// Assembly Line Scheduling

class Solution
{
public:
    int carAssembly(vector<vector<int>> a, vector<vector<int>> t, pair<int, int> e, pair<int, int> x)
    {
        int n = a[0].size();
        vector<vector<int>> dp(2, vector<int>(n, 0));
        dp[0][0] = e.first + a[0][0];
        dp[1][0] = e.second + a[1][0];
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = min(dp[0][i - 1] + a[0][i], dp[1][i - 1] + t[1][i] + a[0][i]);
            dp[1][i] = min(dp[1][i - 1] + a[1][i], dp[0][i - 1] + t[0][i] + a[1][i]);
        }
        dp[0][n - 1] += x.first;
        dp[1][n - 1] += x.second;
        return min(dp[0].back(), dp[1].back());
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n, 0)), t(2, vector<int>(n, 0));
    pair<int, int> e, x;
    for (auto &v : a)
        for (auto &i : v)
            cin >> i;
    for (auto &v : t)
        for (auto &i : v)
            cin >> i;
    cin >> e.first >> e.second;
    cin >> x.first >> x.second;
    cout << Solution().carAssembly(a, t, e, x);
}