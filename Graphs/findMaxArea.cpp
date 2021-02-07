#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &grid, int &cnt)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 0)
            return;
        cnt++;
        grid[r][c] = 0;
        dfs(r + 1, c, grid, cnt);
        dfs(r, c + 1, grid, cnt);
        dfs(r - 1, c, grid, cnt);
        dfs(r, c - 1, grid, cnt);
        dfs(r + 1, c + 1, grid, cnt);
        dfs(r + 1, c - 1, grid, cnt);
        dfs(r - 1, c - 1, grid, cnt);
        dfs(r - 1, c + 1, grid, cnt);
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int cnt = 0;
                dfs(i, j, grid, cnt);
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (auto &v : grid)
        for (int &i : v)
            cin >> i;
    cout << Solution().findMaxArea(grid);
}