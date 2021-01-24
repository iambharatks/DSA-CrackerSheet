#include <bits/stdc++.h>

using namespace std;
//this method is doing queue modification inplace
//using stack
void interLeaveQueue(queue<int> &q)
{
    stack<int> s;
    int halfSize = q.size() / 2;
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < halfSize; i++)
    {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < halfSize; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
//using queue
void interLeave_queue(queue<int> &q)
{
    queue<int> tmpQ;
    int halfSize = q.size() / 2;
    for (int i = 0; i < halfSize; i++)
    {
        tmpQ.push(q.front());
        q.pop();
    }

    while (!tmpQ.empty())
    {
        q.push(tmpQ.front());
        tmpQ.pop();
        q.push(q.front());
        q.pop();
    }
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
    queue<int> q;
    int n;
    cin >> n;
    while (n--)
    {
        int data;
        cin >> data;
        q.push(data);
    }
    // interLeaveQueue(q);
    print(q);
    interLeave_queue(q);
    print(q);
}