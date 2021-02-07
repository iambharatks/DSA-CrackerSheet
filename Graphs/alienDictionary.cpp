#include <bits/stdc++.h>

using namespace std;
// Alien Dictionary
class Graph
{
    int V;
    vector<list<int>> adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }
    void dfs(int u, vector<bool> &visited, string &s)
    {
        visited[u] = true;
        for (int i : adj[u])
        {
            if (!visited[i])
            {
                dfs(i, visited, s);
            }
        }
        s = char(u + 'a') + s;
    }
};

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        Graph g(K);
        for (int i = 0; i < N - 1; i++)
        {
            string u, v;
            u = dict[i];
            v = dict[i + 1];
            int n = min(u.size(), v.size());
            for (int i = 0; i < n; i++)
            {
                if (u[i] != v[i])
                {
                    g.addEdge(u[i] - 'a', v[i] - 'a');
                    break;
                }
            }
        }
        vector<bool> visited(K, 0);
        string s = "";
        for (int i = 0; i < K; ++i)
        {
            if (!visited[i])
                g.dfs(i, visited, s);
        }
        return s;
    }
};

int main()
{
    int N, K;
    cin >> N >> K;
    string dict[N];
    for (string &s : dict)
        cin >> s;
    cout << Solution().findOrder(dict, N, K);
}