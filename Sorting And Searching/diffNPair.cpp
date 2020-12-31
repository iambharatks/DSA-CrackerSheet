#include <bits/stdc++.h>

using namespace std;

// 96.Find Pair Given Difference

int findPairs(vector<int> &a, int L)
{
    sort(a.begin(), a.end());
    int low = 0, high = 1;

    while (high < a.size())
    {
        if (a[high] - a[low] == L)
            return 1;
        if (a[high] - a[low] > L)
        {
            low++;
            high = low + 1;
        }
        else
            high++;
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, l;
        cin >> n >> l;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        cout << findPairs(a, l) << "\n";
    }
}