#include <bits/stdc++.h>

using namespace std;

// Next Smaller Element

//Not in order
void nextSmaller(vector<long long> a)
{
    stack<long long> s;
    for (long long i : a)
    {
        if (s.empty())
        {
            s.push(i);
            continue;
        }
        while (!s.empty() && s.top() > i)
        {
            cout << s.top() << " --> " << i << "\n";
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        cout << s.top() << " --> " << -1 << "\n";
        s.pop();
    }
}

void nextSmallerElement(vector<long long> a)
{
    int n = a.size();
    stack<long long> s;
    vector<long long> nse(n);
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() >= a[i])
            s.pop();
        if (s.empty())
            nse[i] = -1;
        else
            nse[i] = s.top();
        s.push(a[i]);
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << " --> " << nse[i] << "\n";
}

int main()
{
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (long long &i : nums)
        cin >> i;
    nextSmallerElement(nums);
}