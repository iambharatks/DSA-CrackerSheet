#include <bits/stdc++.h>

using namespace std;
//95. Searching in an array where adjacent differ by at most k

int main()
{
    int n, k, x;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    cin >> k >> x;
    int i = 0;
    while (i < n)
    {
        if (a[i] == x)
            break;
        i += max(1, abs(a[i] - x) / k);
    }
    if (i == n)
        cout << "Element not found\n";
    else
        cout << "Element found at " << i + 1 << " position\n";
}