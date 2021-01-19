#include <bits/stdc++.h>

using namespace std;

class getMinQ
{
    deque<int> q;

public:
    void push(int new_element)
    {
        while (!q.empty() && q.back() > new_element)
            q.pop_back();
        q.push_back(new_element);
    }
    void pop(int remove_element)
    {
        if (!q.empty() && q.front() == remove_element)
            q.pop_front();
    }
    bool empty() { return q.empty(); }
    int min() { return q.front(); }
};

int main()
{
    int data = 1;
    getMinQ q;
    while (data)
    {
        cin >> data;
        cout << q.min() << " ";
        q.push(data);
    }
    cout << endl;
    while (!q.empty())
    {
        int min = q.min();
        cout << min << " ";
        q.pop(min);
    }
}