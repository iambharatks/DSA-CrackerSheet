#include <bits/stdc++.h>

using namespace std;
// Merge two binary Max Heaps
//Time complexity := O(n)
//Space complexity := O(n)
void percolateDown(int *arr, int i, int n)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max;
    if (left < n && arr[left] > arr[i])
        max = left;
    else
        max = i;
    if (right < n && arr[right] > arr[max])
        max = right;
    if (max != i)
    {
        swap(arr[i], arr[max]);
        percolateDown(arr, max, n);
    }
}

void heapify(int *arr, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDown(arr, i, n);
}

void mergeMaxHeaps(int *arr1, int n1, int *arr2, int n2, int *merged)
{
    for (int i = 0; i < n1; i++)
        merged[i] = arr1[i];
    for (int i = 0; i < n2; i++)
        merged[n1 + i] = arr2[i];
    heapify(merged, n1 + n2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n1, n2;
        cin >> n1 >> n2;
        int arr1[n1], arr2[n2];
        for (int i = 0; i < n1; i++)
            cin >> arr1[i];
        for (int i = 0; i < n2; i++)
            cin >> arr2[i];
        int *merged = new int[n1 + n2];
        mergeMaxHeaps(arr1, n1, arr2, n2, merged);
        for (int i = 0; i < n1 + n2; i++)
            cout << merged[i] << " ";
        cout << '\n';
    }
}