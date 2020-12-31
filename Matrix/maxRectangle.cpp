#include <bits/stdc++.h>

using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m)
{
    if (n == 0 || m == 0)
        return -1;
    vector<vector<int>> dp(n, vector<int>(m));
    int ans = 0;
    for (int i = 0; i < n; i++)
        dp[i][0] = M[i][0];
    for (int i = 0; i < m; i++)
        dp[0][i] = M[0][i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (M[i][j] == 1)
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            else
                dp[i][j] = 0;
            ans = max(ans, dp[i][j]);
        }
    }
    return ans * ans;
}

int main()
{
    int r, c;
    cin >> r >> c;
    int matrix[MAX][MAX];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    }
    cout << maxArea(matrix, r, c);
}