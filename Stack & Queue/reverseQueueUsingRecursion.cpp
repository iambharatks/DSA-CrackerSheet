#include <bits/stdc++.h>

using namespace std;

void insertAtFront(queue<int> &q, int newElement)
{
    if (q.empty())
        q.push(newElement);
    else
    {
        int current = q.front();
        q.pop();
        insertAtFront(q, newElement);
        q.push(current);
    }
}

void reverseUtil(queue<int> &q)
{
    if (q.empty())
        return;
    int current = q.front();
    q.pop();
    reverseUtil(q);
    q.push(current);
}

queue<int> reverse(queue<int> q)
{
    reverseUtil(q);
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
    queue<int> q;
    int n;
    cin >> n;
    while (n--)
    {
        int data;
        cin >> data;
        q.push(data);
    }
    queue<int> modiq = reverse(q);
    print(q);
    print(modiq);
}