#include <bits/stdc++.h>

using namespace std;
//time complexity O(n*n)
//Space := O(n)
// recursive stacks
void insertAtBottom(stack<int> &s, int new_element)
{
    if (s.empty())
        s.push(new_element);
    else
    {
        int current_element = s.top();
        s.pop();
        insertAtBottom(s, new_element);
        s.push(current_element);
    }
}

void reverse(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int current_element = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, current_element);
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
    stack<int> original_stack = s;
    while (!original_stack.empty())
    {
        cout << original_stack.top() << " ";
        original_stack.pop();
    }
    cout << endl;
    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}