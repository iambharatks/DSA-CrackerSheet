#include <bits/stdc++.h>

using namespace std;

bool isEnd(pair<int, int> p) { return p.first == -1 && p.second == -1; }
bool isSafe(pair<int, int> p, int r, int c) { return (p.first >= 0 && p.second >= 0 && p.first < r && p.second < c); }
int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> Q;
    int r = grid.size(), c = grid[0].size();
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (grid[i][j] == 2)
                Q.push({i, j});
    Q.push({-1, -1});
    pair<int, int> tmp;
    while (!Q.empty())
    {
        tmp = Q.front();
        while (!isEnd(tmp))
        {
            tmp = Q.front();
        }
    }
}

int main()
{
    
}