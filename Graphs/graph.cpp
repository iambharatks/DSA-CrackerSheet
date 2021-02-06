#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Graph
{
    map<T, list<T>> adj;
    bool bidir;

public:
    Graph(bool bidir) : bidir(bidir) {}
    void addEdge(T u, T v)
    {
        adj[u].push_back(v);
        if (bidir)
            adj[v].push_back(u);
    }
    void print()
    {
        for (auto node : adj)
        {
            cout << node.first << " -> ";
            for (auto v : node.second)
                cout << v << " ";
            cout << "\n";
        }
    }
    void dfsUtil(T src, unordered_map<T, bool> &visited)
    {
        visited[src] = true;
        cout << src << " -> ";
        for (auto neigh : adj[src])
            if (!visited[neigh])
                dfsUtil(neigh, visited);
    }
    //Time Complexity := O(V+E)
    void dfs(T src)
    {
        unordered_map<T, bool> visited;
        dfsUtil(src, visited);
        cout << '\n';
    }
    //Time Complexity := O(V+E)
    void bfs(T src)
    {
        map<T, bool> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T v = q.front();
            q.pop();
            cout << v << " -> ";
            for (T neigh : adj[v])
            {
                if (!visited[neigh])
                {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << '\n';
    }
};
int main()
{
    int n;
    cin >> n;
    int u, v, dist;
    Graph<int> g(false);

    while (n--)
    {
        cin >> u >> v >> dist;
        g.addEdge(u, v, dist);
    }
    cin >> u >> v;
    g.dijktras(u);
}
// 1 A B
// 1 B C
// 1 D A
// 1 D B
// 1 C C
// 1 B D
