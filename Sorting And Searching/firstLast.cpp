#include <bits/stdc++.h>

using namespace std;
//88.First and last occurrences of X
//Time : O(logn)
int lowerBound(vector<int> a, int target)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            if (mid > 0 && a[mid - 1] == target)
                high--;
            else
                return mid;
        }
        else if (a[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int upperBound(vector<int> a, int target)
{
    int low = 0, high = a.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            if (mid < a.size() - 1 && a[mid + 1] == target)
                low++;
            else
                return mid;
        }
        else if (a[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
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