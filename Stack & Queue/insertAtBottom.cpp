#include <bits/stdc++.h>

using namespace std;

//Insert an element at its bottom without using any other datastructure
//Time Complexity is O(n*n)
void insertAtBottom(stack<int> &s, int new_element)
{
    if (s.empty())
    {
        s.push(new_element);
        return;
    }
    int current_element = s.top();
    s.pop();
    insertAtBottom(s, new_element);
    s.push(current_element);
}

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    while (n--)
    {
        int data;
        cin >> data;
        insertAtBottom(s, data);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}