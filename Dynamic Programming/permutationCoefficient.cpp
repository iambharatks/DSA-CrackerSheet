#include <bits/stdc++.h>

using namespace std;

//Permutation Coefficient Problem

class recursive
{
public:
    int factorial(int n)
    {
        if (n <= 1)
            return 1;
        return n * factorial(n - 1);
    }
    int nPr(int n, int r)
    {
        if (n < r)
            return 0;
        if (r == 0)
            return 1;
        if (r == n)
            return factorial(n);
        return r * nPr(n - 1, r - 1) + nPr(n - 1, r);
    }
};

class tabulation
{
    //Time Complexity:= O(n*r)
public:
    int nPr(int n, int r)
    {
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= r; j++)
            {
                if (i < j)
                    dp[i][j] = 0;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = j * dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n][r];
    }
};

class Optimal
{
public:
    //Time Comlpexity := O(n)
    int nPr(int n, int r)
    {
        vector<long long int> factorial(n + 1, 1);
        for (int i = 2; i <= n; i++)
            factorial[i] = i * factorial[i - 1];
        return factorial[n] / factorial[n - r];
    }
};
int main()
{
    int n, r;
    cin >> n >> r;
    cout << Optimal().nPr(n, r);
}