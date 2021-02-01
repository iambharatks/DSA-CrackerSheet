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
};

int main()
{
    Graph<char> g(true);
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
        case 0:
            cout << "Quiting...\n";
        }
    }
}