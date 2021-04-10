#include <bits/stdc++.h>

using namespace std;

// Partition Equal Subset Sum 

const int n = 2e5;

class recursion
{
public:
    bool equalPartitionUtil(int N, int arr[], int sum, int subs)
    {
        if (subs == sum / 2)
            return true;
        if (N < 0)
            return false;
        return equalPartitionUtil(N - 1, arr, sum, subs + arr[N - 1]) || equalPartitionUtil(N - 1, arr, sum, subs);
    }
    bool equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += arr[i];
        if (sum & 1)
            return false;
        return equalPartitionUtil(N, arr, sum, 0);
    }
};

class memoization
{
    vector<vector<int>> table;

public:
    bool equalPartitionUtil(int N, int arr[], int sum, int subs)
    {
        if (subs == sum / 2)
            return true;
        if (N < 0 || subs > sum / 2)
            return false;
        if (table[subs][N] != -1)
            return table[subs][N];
        return table[subs][N] = equalPartitionUtil(N - 1, arr, sum, subs + arr[N - 1]) || equalPartitionUtil(N - 1, arr, sum, subs);
    }
    bool equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += arr[i];
        if (sum & 1)
            return false;
        table.resize(sum / 2 + 1, vector<int>(N + 1, -1));
        return equalPartitionUtil(N, arr, sum, 0);
    }
};

class tabulation
{

public:
    bool equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; ++i)
            sum += arr[i];
        if (sum & 1)
            return false;
        vector<vector<bool>> dp(sum / 2 + 1, vector<bool>(N + 1, 0));

        //Initialization
        for (int i = 0; i <= N; i++)
            dp[0][i] = 1;
        for (int i = 0; i <= sum / 2; i++)
            dp[i][0] = 0;

        //Calculation
        for (int i = 1; i <= sum / 2; ++i)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i >= arr[j - 1])
                    dp[i][j] = dp[i][j - 1] || dp[i - arr[j - 1]][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[sum / 2][N];
    }
};
class Optimized
{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum & 1)
            return false;
        bool dp[sum / 2 + 1][N + 1];
        memset(dp, 0, sizeof(dp));

        //Initialization
        for (int i = 0; i <= sum / 2; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= N; i++)
            dp[0][i] = 1;

        //Calculation
        for (int i = 1; i <= sum / 2; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i >= arr[j - 1])
                    dp[i][j] = dp[i][j - 1] || dp[i - arr[j - 1]][j - 1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[sum / 2][N];
    }
};
int main()
{
    int N;
    cin >> N;
    int arr[n];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    bool isPossible = Optimized().equalPartition(N, arr);
    if (isPossible)
        cout << "Yes";
    else
        cout << "No";
}