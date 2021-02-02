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
    Graph<char> g(false);
    int choice = 1;
    char u, v;
    while (choice)
    {
        cout << "Select your choice\n\t1.add edge\n\t2.print graph\n\t3.dfs\n\t4.bfs\n\t0.Quite\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter vertices\n";
            cin >> u >> v;
            g.addEdge(u, v);
            break;
        case 2:
            g.print();
            break;
        case 3:
            cout << "Enter source\n";
            cin >> u;
            g.dfs(u);
            break;
        case 4:
            cout << "Enter source\n";
            cin >> u;
            g.bfs(u);
            break;
        case 5:
            cin >> u;
            cout << g.cycleBFS(u) << "\n";
            break;
        case 0:
            cout << "Quiting...\n";
        }
    }
}
// 1 A B
// 1 B C
// 1 D A
// 1 D B
// 1 C C
// 1 B D
