#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V) : V(V), adj(new list<int>[V]) {}
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool isCycle(int src, bool *visited, int parent)
    {
        visited[src] = true;
        for (auto neighb : adj[src])
        {
            if (!visited[neighb])
            {
                if (isCycle(neighb, visited, src))
                    return true;
            }
            else if (neighb != parent)
                return true;
        }
        return false;
    }
    bool isTree()
    {
        bool visited[V];
        memset(visited, 0, V);

        //1.tree doesn't have cycle
        if (isCycle(0, visited, -1))
            return false;

        //2.all nodes are connected int tree
        for (int i = 0; i < V; ++i)
            if (!visited[i])
                return false;

        return true;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;
    Graph graph(V);
    int u, v;
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    cout << graph.isTree() << " ";
}