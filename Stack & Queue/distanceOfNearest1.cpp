#include <bits/stdc++.h>

using namespace std;
// Distance of nearest cell having 1
//Approach Using Graph
//Time complexity := O(n*m)
//Space Complexity := O(n*m)
void createGraph(vector<vector<int>> &adj, int r, int c)
{
    int k = 1;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i == r && j != c)
            {
                adj[k].push_back(k + 1);
                adj[k + 1].push_back(k);
            }
            else if (i != r && j == c)
            {
                adj[k].push_back(k + c);
                adj[k + c].push_back(k);
            }
            else if (i != r && j != c)
            {
                adj[k].push_back(k + 1);
                adj[k + 1].push_back(k);
                adj[k].push_back(k + c);
                adj[k + c].push_back(k);
            }
            k++;
        }
    }
}

void bfs(vector<vector<int>> &adj, queue<int> &q, vector<int> &dist, vector<bool> &visit)
{
    int tmp;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        for (int neigh : adj[tmp])
        {
            if (!visit[neigh])
            {
                dist[neigh] = min(dist[neigh], dist[tmp] + 1);
                q.push(neigh);
                visit[neigh] = true;
            }
        }
    }
}

vector<vector<int>> nearestUsingGraph(vector<vector<int>> grid)
{
    int r = grid.size();
    int c = grid[0].size();
    vector<vector<int>> adj(r * c + 1);
    createGraph(adj, r, c);
    vector<int> dist(r * c + 1, INT_MAX);
    vector<bool> visit(r * c + 1, 0);
    int k = 1;
    queue<int> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 1)
            {
                dist[k] = 0;
                visit[k] = true;
                q.push(k);
            }
            k++;
        }
    }
    bfs(adj, q, dist, visit);
    for (int i = 1; i < r * c + 1; i++)
    {
        int row = (i - 1) / c;
        int col = i - row * c - 1;
        grid[row][col] = dist[i];
    }
    return grid;
}

//Naive Approach
int findDist(pair<int, int> p1, pair<int, int> p2) { return abs(p1.first - p2.first) + abs(p1.second - p2.second); }
int findNearest(pair<int, int> p, queue<pair<int, int>> Q)
{
    pair<int, int> tmp;
    int minDist = INT_MAX;
    while (!Q.empty())
    {
        tmp = Q.front();
        Q.pop();
        minDist = min(minDist, findDist(tmp, p));
    }
    return minDist;
}

vector<vector<int>> nearest(vector<vector<int>> grid)
{
    int r = grid.size();
    int c = grid[0].size();
    queue<pair<int, int>> Q;
    vector<vector<int>> soln(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (grid[i][j] == 1)
                Q.push({i, j});

    vector<pair<int, int>> V;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (grid[i][j] == 0)
                V.push_back({i, j});
        }
    }
    for (pair<int, int> p : V)
        soln[p.first][p.second] = findNearest(p, Q);
    return soln;
}
//TODO DP Approach
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    for (auto &v : grid)
        for (int &i : v)
            cin >> i;
    vector<vector<int>> soln = nearestUsingGraph(grid);
    for (auto &v : soln)
    {
        for (int &i : v)
            cout << i << " ";
        cout << "\n";
    }
}