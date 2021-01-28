#include <bits/stdc++.h>

using namespace std;
//88.First and last occurrences of X
//Time : O(logn)
int lowerBound(vector<int> a, int target)
{
    int low = 0, high = a.size() - 1;
    int idx = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] >= target)
        {
            idx = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    if (idx != -1 && a[idx] != target)
        return -1;
    return idx;
}
int upperBound(vector<int> a, int target)
{
    int low = 0, high = a.size() - 1;
    int idx = high + 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] <= target)
        {
            idx = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    if (idx != high + 1 && a[idx] < target)
        return -1;
    return idx;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> n >> target;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        int lb = lowerBound(a, target);
        int ub = upperBound(a, target);
        if (lb == -1)
            cout << -1 << "\n";
        else
            cout << lb << " " << ub << "\n";
    }
}