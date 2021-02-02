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
    //dfs
    bool dfsUtil(T src, unordered_map<T, bool> &visited, T parent)
    {
        visited[src] = true;
        for (T neigh : adj[src])
        {
            if (!visited[neigh])
            {
                if (dfsUtil(neigh, visited, src))
                    return true;
            }
            else if (neigh != parent)
                return true;
        }
        return false;
    }
    //dfs
    bool hasCycle()
    {
        unordered_map<T, bool> visited;
        for (auto v : adj)
        {
            if (!visited[v.first])
                if (dfsUtil(v.first, visited, -1))
                    return true;
        }
        return false;
    }
    
};

int main()
{
    Graph<char> g(true);
    int choice = 1;
    char u, v;
    int edges;
    cin >> edges;
    while (edges--)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    cin >> u;
    g.print();
    g.bfs(u);
    cout << g.hasCycle();
}
// 6
// A B
// B C
// D A
// D B
// C C
// B D
