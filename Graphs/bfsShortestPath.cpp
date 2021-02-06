#include <bits/stdc++.h>

using namespace std;
#define INF INT_MAX
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
    //Time complexity := O(E*logV)
    void bfs_sssp(T src)
    {
        map<T, int> distance;
        map<T, T> parent;
        for (auto i : adj)
            distance[i.first] = INF;
        queue<T> q;
        q.push(src);
        distance[src] = 0;
        parent[src] = src;
        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            // cout << node << " ";
            for (auto neigh : adj[node])
            {
                if (distance[neigh] == INF)
                {
                    q.push(neigh);
                    distance[neigh] = distance[node] + 1;
                    parent[neigh] = node;
                }
            }
        }
        for (auto i : adj)
            cout << "distance from " << src << " to " << i.first << " is " << distance[i.first] << "\n";
    }
};
int main()
{
    int n;
    cin >> n;
    char u, v;
    Graph<char> g(true);

    while (n--)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    // g.print();
    cin >> u;
    g.bfs_sssp(u);
}
