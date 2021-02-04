#include <bits/stdc++.h>

using namespace std;
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
    void dfs(T src, unordered_map<T, bool> &visited, vector<T> &ts)
    {
        visited[src] = true;
        for (T neigh : adj[src])
        {
            if (!visited[neigh])
                dfs(neigh, visited, ts);
        }
        ts.push_back(src);
    }
    vector<T> topSort()
    {
        int N = adj.size();
        unordered_map<T, bool> visited;
        vector<T> ts;
        for (auto node : adj)
        {
            if (!visited[node.first])
                dfs(node.first, visited, ts);
        }
        reverse(ts.begin(), ts.end());
        return ts;
    }
};

int main()
{
    int n;
    cin >> n;
    Graph<char> g;
    while (n--)
    {
        char u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.print();
    vector<char> ts = g.topSort();
    for (char i : ts)
        cout << i << " ";
}