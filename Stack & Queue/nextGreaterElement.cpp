#include <bits/stdc++.h>

using namespace std;

// Next Greater Element
// not in same order of input
void nextLargerElement(vector<long long> arr)
{
    stack<long long> s;
    int n = arr.size();
    s.push(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }
        while (!s.empty() && s.top() < arr[i])
        {
            cout << s.top() << " --> " << arr[i] << "\n";
            s.pop();
        }
        s.push(arr[i]);
    }
    while (!s.empty())
    {
        cout << s.top() << " --> " << -1 << "\n";
        s.pop();
    }
}

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
            s.pop();
        long long tmp = arr[i];
        if (s.empty())
            arr[i] = -1;
        else
            arr[i] = s.top();
        s.push(tmp);
    }
    return arr;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (long long &i : arr)
        cin >> i;
    nextLargerElement(arr);
    vector<long long> nge = nextLargerElement(arr, n);
    for (long long i : nge)
        cout << i << " ";
}