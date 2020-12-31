#include <bits/stdc++.h>

using namespace std;
//89.Value equal to index value

vector<int> valueEqualToIndex(int arr[], int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
            ans.push_back(i + 1);
    }
    return ans;
}
//constraint: sorted array
int hasFixedPoint(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid + 1 == arr[mid])
            return mid + 1;
        if (mid + 1 > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << hasFixedPoint(arr, n) << endl;
    vector<int> ans = valueEqualToIndex(arr, n);
    for (int i : ans)
        cout << i << " ";
}