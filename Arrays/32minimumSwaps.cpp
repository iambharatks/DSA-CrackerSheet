#include <bits/stdc++.h>

using namespace std;
//32. Minimum swaps and K together
void minimumSwap(vector<int> a, int k)
{
    int count = 0, n = a.size();
    for (int i : a)
    {
        if (i <= k)
            ++count;
    }
    int bad = 0;
    for (int i = 0; i < count; ++i)
    {
        if (a[i] > k)
            ++bad;
    }
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j)
    {
        if (a[i] > k)
            --bad;
        if (a[j] > k)
            ++bad;
        ans = (ans > bad) ? bad : ans;
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        cin >> k;
        minimumSwap(v, k);
    }
}