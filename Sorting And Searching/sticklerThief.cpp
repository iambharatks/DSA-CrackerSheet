#include <bits/stdc++.h>

using namespace std;

//98. maximum sum such that no 2 elements are adjacent
//Both are using dynamic programming
int dynamicSoln(vector<int> &a)
{
    int n = a.size();
    vector<int> dp(n + 1, 0);
    dp[1] = a[0];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 2] + a[i - 1], dp[i - 1]);
    }
    return dp[n];
}
int includeExlude(vector<int> &a)
{
    int n = a.size();
    int exl = 0, inc = a[0], exl_new = 0;
    for (int i = 1; i < n; i++)
    {
        exl_new = (inc > exl) ? inc : exl;
        inc = exl + a[i];
        exl = exl_new;
    }
    return (inc > exl) ? inc : exl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        cout << includeExlude(a) << "\n";
    }
}