#include <bits/stdc++.h>

using namespace std;

bool mirror(vector<stack<int>> &tree1, vector<queue<int>> &tree2)
{
    for (int i = 1; i < tree1.size(); i++)
    {
        stack<int> &s = tree1[i];
        queue<int> &q = tree2[i];
        while (!s.empty() && !q.empty())
        {
            if (s.top() != q.front())
                return false;
            s.pop();
            q.pop();
        }
        if (!s.empty() || !q.empty())
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vector<stack<int>> tree1(n + 1);
        vector<queue<int>> tree2(n + 1);
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            tree1[u].push(v);
        }
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            tree2[u].push(v);
        }
        cout << mirror(tree1, tree2) << "\n";
    }
}