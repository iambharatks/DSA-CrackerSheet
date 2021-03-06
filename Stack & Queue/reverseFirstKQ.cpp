#include <bits/stdc++.h>

using namespace std;
queue<int> modifyQueue(queue<int> q, int k)
{
    queue<int> tmpQ;
    stack<int> tmpS;
    while (k--)
    {
        tmpS.push(q.front());
        q.pop();
    }
    while (!q.empty())
    {
        tmpQ.push(q.front());
        q.pop();
    }
    while (!tmpS.empty())
    {
        q.push(tmpS.top());
        tmpS.pop();
    }
    while (!tmpQ.empty())
    {
        q.push(tmpQ.front());
        tmpQ.pop();
    }
    return q;
}
void print(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}
int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        q.push(data);
    }
    queue<int> newQ = modifyQueue(q, k);
    cout << "Original Queue\n";
    print(q);
    cout << "K reverse Queue\n";
    print(newQ);
}