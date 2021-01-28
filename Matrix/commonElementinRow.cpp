#include <bits/stdc++.h>

using namespace std;

// Common elements in all rows of a given matrix

void commonInRows(vector<vector<int>> mat)
{
    int n = mat.size();
    int m = mat[0].size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[mat[i][j]] == i)
                mp[mat[i][j]]++;
        }
    }
    for (auto p : mp)
        if (p.second == n)
            cout << p.first << " ";
    cout << '\n';
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (auto &v : mat)
        for (int &i : v)
            cin >> i;
    commonInRows(mat);
}