#include <bits/stdc++.h>

using namespace std;
//cycle detection in undirected Graphs
//using BFS
//using DFS
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
    bool hasCycleDFS()
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
    bool bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;
        q.push(src);
        visited[src] = true;
        unordered_map<T, T> parent;
        parent[src] = '#';
        while (!q.empty())
        {
            T v = q.front();
            q.pop();
            for (int neigh : adj[v])
            {
                if (!visited[neigh])
                {
                    parent[neigh] = v;
                    visited[neigh] = true;
                    q.push(neigh);
                }
                else if (parent[v] != neigh)
                    return true;
            }
        }
        return false;
    }
    bool hasCycleBFS()
    {
        unordered_map<T, bool> visited;
        for (auto node : adj)
        {
            if (!visited[node.first])
                if (bfs(node.first, visited))
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
    cout << g.hasCycleBFS();
}
// 6
// A B
// B C
// D A
// D B
// C C
// B D
