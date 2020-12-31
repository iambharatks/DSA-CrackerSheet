#include <bits/stdc++.h>

using namespace std;
//90.Search element in rotated sorted array
int pivot(vector<int> a)
{
    int n = a.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // cout << low << " " << mid << " " << high << "\n";
        if (mid < high && a[mid] > a[mid + 1])
            return mid;
        if (mid > low && a[mid] < a[mid - 1])
            return mid - 1;
        if (a[low] >= a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int search(vector<int> a, int target)
{
    int n = a.size();
    int piv = pivot(a);
    // cout << piv << "\n";
    int low, high;
    if (piv != -1 && a[piv] == target)
        return piv;
    if (piv == -1)
        low = 0, high = n - 1;
    else if (a[0] <= target)
        low = 0, high = piv - 1;
    else
        low = piv + 1, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // cout << a[low] << " " << a[mid] << " " << a[high] << "\n";
        if (a[mid] == target)
            return mid;
        if (a[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> a(n, 0);
    for (int &i : a)
        cin >> i;
    cout << search(a, target) << "\n";
}