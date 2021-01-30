#include <bits/stdc++.h>

using namespace std;
//using minHeap
//without sorted output
//Time Complexity := O(n)
//Space Complexity := O(1)
//with sorted output
//Time Complexity := O(n + k*logk)
//Space Complexity := O(1)

void percolateDown(int *arr, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min;
    if (left < n && arr[left] < arr[i])
        min = left;
    else
        min = i;
    if (right < n && arr[right] < arr[min])
        min = right;
    if (min != i)
    {
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
        percolateDown(arr, min, n);
    }
}

void heapify(int *arr, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDown(arr, i, n);
}
vector<int> kLargest(int arr[], int n, int k)
{
    // code here
    vector<int> ans(k);
    heapify(arr, k);
    for (int i = k; i < n; i++)
    {
        if (arr[0] > arr[i])
            continue;
        else
        {
            arr[0] = arr[i];
            percolateDown(arr, 0, k);
        }
    }
    for (int i = 0; i < k; i++)
        ans[i] = arr[i];
    sort(ans.begin(), ans.end(), greater<int>());
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    vector<int> ans = kLargest(arr, n, k);
    for (int i : ans)
        cout << i << " ";
}