#include <bits/stdc++.h>

using namespace std;

template <typename T>
//DAG
class Graph
{
    map<T, list<T>> adj;
    map<T, int> indegree;

public:
    void addEdge(T u, T v)
    {
        adj[u].push_back(v);
        adj[v];
        indegree[v]++;
    }
    void printTimeTaken()
    {
        queue<T> q;
        map<T, int> job;
        for (auto it : adj)
        {
            if (indegree[it.first] == 0)
            {
                q.push(it.first);
                job[it.first] = 1;
            }
        }
        while (!q.empty())
        {
            T cur = q.front();
            q.pop();
            for (auto neigh : adj[cur])
            {
                indegree[neigh]--;
                job[neigh] = max(job[neigh], job[cur] + 1);
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        for (auto it : job)
            cout << it.first << " takes " << it.second << " unit time\n";
    }
};

int main()
{
    int n, u, v;
    cin >> n;
    Graph<int> g;
    while (n--)
    {
        cin >> u >> v;
        g.addEdge(u, v);
    }
    g.printTimeTaken();
}