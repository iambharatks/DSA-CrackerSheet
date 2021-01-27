#include <bits/stdc++.h>

using namespace std;
// Find a specific pair in Matrix
int findMaxValue(vector<vector<int>> mat)
{
    int n = mat.size();
    int maxDiff = INT_MIN;
    vector<vector<int>> max(n, vector<int>(n, INT_MIN));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == n - 1)
                max[i][j] = mat[i][j];
            else if (i == n - 1)
                max[i][j] = (max[i][j + 1] > mat[i][j]) ? max[i][j + 1] : mat[i][j];
            else if (j == n - 1)
                max[i][j] = (max[i + 1][j] > mat[i][j]) ? max[i + 1][j] : mat[i][j];
            else
            {
                max[i][j] = (max[i][j + 1] > mat[i][j]) ? max[i][j + 1] : mat[i][j];
                max[i][j] = (max[i + 1][j] > mat[i][j]) ? max[i + 1][j] : mat[i][j];
                if (max[i + 1][j + 1] - mat[i][j] > maxDiff)
                    maxDiff = max[i + 1][j + 1] - mat[i][j];
                cout << max[i + 1][j + 1] << " " << mat[i][j] << " " << max[i + 1][j + 1] - mat[i][j] << "\n";
            }
        }
    }
    return maxDiff;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto &v : mat)
        for (int &i : v)
            cin >> i;
    cout << findMaxValue(mat);
}