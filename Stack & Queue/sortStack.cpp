#include <bits/stdc++.h>

using namespace std;

void insert(stack<int> &s, int new_element)
{
    if (s.empty() || s.top() <= new_element)
    {
        s.push(new_element);
        return;
    }
    int current_element = s.top();
    s.pop();
    insert(s, new_element);
    s.push(current_element);
}

void sort(stack<int> &s)
{
    if (s.empty())
        return;
    int current_element = s.top();
    s.pop();
    sort(s);
    insert(s, current_element);
}

//print a copy of stack
void print(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    int n, data;
    cin >> n;
    while (n--)
    {
        cin >> data;
        s.push(data);
    }
    n = s.size();
    cout << "original stack\n";
    print(s);
    sort(s);
    cout << "sorted stack\n";
    print(s);
}