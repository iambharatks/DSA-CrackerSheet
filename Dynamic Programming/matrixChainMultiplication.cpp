#include <bits/stdc++.h>

using namespace std;

const int n = 100000;

// Matrix Chain Multiplication

class recursive
{
public:
    int matrixMultipliactionUtil(int arr[], int i, int j)
    {
        if (i == j)
            return 0;
        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int tmp = matrixMultipliactionUtil(arr, i, k) + matrixMultipliactionUtil(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
            ans = min(ans, tmp);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return matrixMultipliactionUtil(arr, 1, N - 1);
    }
};

class memoization
{
public:
    int matrixMultipliactionUtil(int arr[], int i, int j, vector<vector<int>> &table)
    {
        if (i == j)
            return 0;
        if (table[i][j] != INT_MAX)
            return table[i][j];
        for (int k = i; k < j; k++)
        {
            int tmp = matrixMultipliactionUtil(arr, i, k, table) + matrixMultipliactionUtil(arr, k + 1, j, table) + arr[i - 1] * arr[k] * arr[j];
            table[i][j] = min(table[i][j], tmp);
        }
        return table[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> table(N, vector<int>(N, INT_MAX));
        return matrixMultipliactionUtil(arr, 1, N - 1, table);
    }
};

//In every step we will calculate for L length Matrix chain
// L varies from 2 to N-1
// Hence, result will always be precomputed
class tabulation
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
        // Initialization
        for (int i = 1; i < N; i++)
            dp[i][i] = 0;

        // Calculation
        for (int L = 2; L < N; L++)
        {
            for (int i = 1; i <= N - L; i++)
            {
                int j = i + L - 1;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
                }
            }
        }

        return dp[1][N - 1];
    }
};
int main()
{
    int N;
    cin >> N;
    int arr[n];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << tabulation().matrixMultiplication(N, arr);
}