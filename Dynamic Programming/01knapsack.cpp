#include <bits/stdc++.h>

using namespace std;

#define N 100000

class recursive
{
    //Time Complexity := O(2^n)
public:
    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapSack(int W, int wt[], int val[], int n)
    {
        if (W == 0 || n <= 0)
            return 0;
        int excluding = knapSack(W, wt, val, n - 1);
        if (W >= wt[n - 1])
        {
            int including = knapSack(W - wt[n - 1], wt, val, n - 1) + val[n - 1];
            return max(excluding, including);
        }
        return excluding;
    }
};
class memoization
{
    // Time Complexity :O(n*m)
public:
    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapSackUtil(int W, int wt[], int val[], int n, vector<vector<int>> &table)
    {
        if (W == 0 || n <= 0)
            return 0;
        if (table[W][n - 1] != -1)
            return table[W][n - 1];
        int excluding = knapSackUtil(W, wt, val, n - 1, table);
        if (W >= wt[n - 1])
        {
            int including = knapSackUtil(W - wt[n - 1], wt, val, n - 1, table) + val[n - 1];
            return table[W][n - 1] = max(including, excluding);
        }
        return table[W][n - 1] = excluding;
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> table(W + 1, vector<int>(n, -1));
        return knapSackUtil(W, wt, val, n, table);
    }
};

class tabulation
{
    //Time Complexity :O(n*m)
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        int excluding, including;
        vector<vector<int>> dp(W + 1, vector<int>(n + 1, -1));
        //Initializtion
        for (int i = 0; i <= n; i++)
            dp[0][i] = 0;
        // think?
        for (int i = 1; i < W + 1; i++)
            dp[i][0] = 0;
        for (int i = 1; i < W + 1; i++)
        {
            excluding = 0, including = 0;
            for (int j = 1; j <= n; j++)
            {
                excluding = dp[i][j - 1];
                if (i >= wt[j - 1])
                    including = dp[i - wt[j - 1]][j - 1] + val[j - 1];
                dp[i][j] = max(excluding, including);
            }
        }
        return dp[W][n];
    }
};

int main()
{
    int n, w;
    cin >> n >> w;
    int wt[N];
    int val[N];
    for (int i = 0; i < n; i++)
        cin >> wt[i];
    for (int i = 0; i < n; i++)
        cin >> val[i];
    cout << tabulation().knapSack(w, wt, val, n);
}