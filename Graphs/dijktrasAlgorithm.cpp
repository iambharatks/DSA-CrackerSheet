#include <bits/stdc++.h>

using namespace std;
template <typename T>
class Graph
{
    map<T, list<pair<T, int>>> adj;
    bool bidir;

public:
    Graph(bool bidir) : bidir(bidir) {}
    void addEdge(T u, T v, int dist)
    {
        adj[u].push_back({v, dist});
        if (bidir)
            adj[v].push_back({u, dist});
    }
    void print()
    {
        for (auto node : adj)
        {
            cout << node.first << " -> ";
            for (auto v : node.second)
                cout << "(" << v.first << "," << v.second << ") ";
            cout << "\n";
        }
    }
    //Time complexity := O(E*logV)
    void dijktras(T src)
    {
        unordered_map<T, int> dist;
        unordered_map<T, T> prev;
        for (auto it : adj)
            dist[it.first] = INT_MAX;
        set<pair<int, T>> pq;
        pq.insert({0, src});
        dist[src] = 0;
        while (!pq.empty())
        {
            pair<int, T> p = *pq.begin();
            pq.erase(pq.begin());
            T node = p.second;
            int nodeDist = p.first;
            for (auto neigh : adj[node])
            {
                int newDist = nodeDist + neigh.second;
                if (newDist < dist[neigh.first])
                {
                    auto f = pq.find({dist[neigh.first], neigh.first});
                    prev[neigh.first] = node;
                    if (f != pq.end())
                        pq.erase(f);
                    dist[neigh.first] = newDist;
                    pq.insert({newDist, neigh.first});
                }
            }
        }
        for (auto v : dist)
            cout << src << " -> " << v.first << " : " << v.second << "\n";
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