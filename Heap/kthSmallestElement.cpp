#include <bits/stdc++.h>

using namespace std;
//Kth smallest element
//using maxHeap
//Time complexity := O(n)
//space complexity := O(1)

//Kth largest element
//using minHeap
//Time complexity := O(n)
//space complexity := O(1)
void percolateDownMax(int *arr, int i, int n)
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
        int tmp = arr[i];
        arr[i] = arr[max];
        arr[max] = tmp;
        percolateDownMax(arr, max, n);
    }
}
void maxHeap(int *arr, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDownMax(arr, i, n);
}
void percolateDownMin(int *arr, int i, int n)
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
        percolateDownMin(arr, min, n);
    }
}
void minHeap(int *arr, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDownMin(arr, i, n);
}
int kthSmallest(int arr[], int l, int r, int k)
{
    //code here
    maxHeap(arr + l, k);
    for (int i = k; i <= r; i++)
    {
        if (arr[l] <= arr[i])
            continue;
        arr[l] = arr[i];
        percolateDownMax(arr + l, 0, k);
    }
    return arr[l];
}
int kthLargestElement(int arr[], int l, int r, int k)
{
    minHeap(arr + l, k);
    for (int i = k; i <= r; i++)
    {
        if (arr[l] <= arr[i])
            continue;
        arr[l] = arr[i];
        percolateDownMin(arr + l, 0, k);
    }
    return arr[l];
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    cout << kthSmallest(arr, 0, n, k);
}