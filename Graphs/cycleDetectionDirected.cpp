#include <bits/stdc++.h>

using namespace std;
//Detect cycle in a directed graph
// using DFS
// To detect a back edge,
//  keep track of vertices currently in the recursion stack of function for DFS traversal.
//  If a vertex is reached that is already in the recursion stack,
//  then there is a cycle in the tree.

//directed graph
template <typename T>
class Graph
{
    map<T, list<T>> adj;

public:
    void addEdge(T u, T v)
    {
        adj[u].push_back(v);
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
    bool dfsUtil(T src, unordered_map<T, bool> &visited, unordered_map<T, bool> &reStack)
    {
        visited[src] = true;
        reStack[src] = true;
        for (T neigh : adj[src])
        {
            if (!visited[neigh] && dfsUtil(neigh, visited, reStack))
                return true;
            else if (reStack[neigh])
                return true;
        }
        reStack[src] = false;
        return false;
    }
    //Time Complexity := O(V+E)
    bool hasCycleDFS()
    {
        unordered_map<T, bool> visited;
        unordered_map<T, bool> reStack;
        for (auto v : adj)
        {
            if (!visited[v.first] && dfsUtil(v.first, visited, reStack))
                return true;
        }
        return false;
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
    Graph<char> g;
    int choice = 1;
    char u, v;
    int edges;
    cin >> edges;
    while (edges--)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.print();
    cout << g.hasCycleDFS();
}
