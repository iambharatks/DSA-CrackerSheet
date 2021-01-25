#include <bits/stdc++.h>

using namespace std;

//Aproach using queue
//Time Complexity := O(n)
//space Complexity := O(k)
void printFirstNegativeNumber(vector<int> a, int k)
{
    int n = a.size();
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        if (a[i] < 0)
            q.push(i);
    }
    for (int i = k; i < n; ++i)
    {
        if (!q.empty())
            cout << a[q.front()] << " ";
        else
            cout << 0 << " ";
        while ((!q.empty()) && q.front() < (i - k + 1))
            q.pop();
        if (a[i] < 0)
            q.push(i);
    }
    if (!q.empty())
        cout << a[q.front()] << " ";
    else
        cout << 0 << " ";
    cout << "\n";
}

void printFirstNeg(vector<int> a, int k)
{
    int firstNegPos = 0;
    int n = a.size();
    for (int i = k - 1; i < n; i++)
    {
        while (firstNegPos < i && (firstNegPos <= i - k || a[firstNegPos] > 0))
            firstNegPos++;
        if (a[firstNegPos] < 0)
            cout << a[firstNegPos] << " ";
        else
            cout << "0 ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        cin >> k;
        printFirstNeg(a, k);
    }
}