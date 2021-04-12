#include <bits/stdc++.h>

using namespace std;

// Maximize The Cut Segments 

class recursion
{
    int maxim(int a, int b, int c) { return max(a, max(b, c)); }

public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        int cutX, cutY, cutZ;
        if (n < 0)
            return -1;
        if (n == 0)
            return 0;
        cutX = maximizeTheCuts(n - x, x, y, z);
        cutY = maximizeTheCuts(n - y, x, y, z);
        cutZ = maximizeTheCuts(n - z, x, y, z);
        return maxim((cutX == -1) ? -1 : cutX + 1, (cutY == -1) ? -1 : cutY + 1, (cutZ == -1) ? -1 : cutZ + 1);
    }
};

class memoization
{
    int maxim(int a, int b, int c) { return max(a, max(b, c)); }
    vector<int> table;

public:
    int maximizeTheCutsUtil(int n, int x, int y, int z)
    {
        int cutX, cutY, cutZ;
        if (n < 0)
            return -1;
        if (table[n] != -2)
            return table[n];
        cutX = maximizeTheCutsUtil(n - x, x, y, z);
        cutY = maximizeTheCutsUtil(n - y, x, y, z);
        cutZ = maximizeTheCutsUtil(n - z, x, y, z);
        return table[n] = maxim((cutX == -1) ? -1 : cutX + 1, (cutY == -1) ? -1 : cutY + 1, (cutZ == -1) ? -1 : cutZ + 1);
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        table.resize(n + 1, -2);
        table[0] = 0;
        maximizeTheCutsUtil(n, x, y, z);
        return (table[n] == -1) ? 0 : table[n];
    }
};

class Solution
{
public:
    //Complete this function
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i >= x)
                dp[i] = max(dp[i], (dp[i - x] == -1) ? -1 : dp[i - x] + 1);
            if (i >= y)
                dp[i] = max(dp[i], (dp[i - y] == -1) ? -1 : dp[i - y] + 1);
            if (i >= z)
                dp[i] = max(dp[i], (dp[i - z] == -1) ? -1 : dp[i - z] + 1);
            // cout << i << " " << dp[i] << "\n";
        }
        return (dp[n] == -1) ? 0 : dp[n];
    }
};
int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << memoization().maximizeTheCuts(n, x, y, z);
}