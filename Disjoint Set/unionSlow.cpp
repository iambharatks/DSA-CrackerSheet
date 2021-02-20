#include <bits/stdc++.h>

using namespace std;

template <typename T>
class DisjointSet
{
    map<T, T> parent;
    T null;

public:
    DisjointSet(T null) : null(null) {}
    T FIND(T X)
    {
        T group = null;
        if (parent[X])
        {
            while (parent[X] != X)
                X = parent[X];
            group = X;
        }
        return group;
    }
    void UNION(T X, T Y)
    {
        if (FIND(X) == FIND(Y) && FIND(X) != null)
            return;
        parent[X] = Y;
    }
    void dfs(T src, unordered_map<T, bool> &visited)
    {
        visited[src] = true;
        if (parent[src] == src)
        {
            cout << src << " ";
            return;
        }
        if (!visited[parent[src]])
            dfs(parent[src], visited);
        cout << src << " ";
    }
    void printGroups()
    {
        unordered_map<T, bool> visited;
        for (auto node : parent)
        {
            if (!visited[node.first])
                dfs(node.first, visited);
            cout << "\n";
        }
    }
    void printParent()
    {
        for (auto node : parent)
            cout << node.first << " --> " << node.second << "\n";
        cout << '\n';
    }
};

int main()
{
    int n, u, v;
    cin >> n;
    DisjointSet<int> dsu(-1);
    while (n--)
    {
        cin >> u >> v;
        dsu.UNION(u, v);
    }
    dsu.printGroups();
    dsu.printParent();
}