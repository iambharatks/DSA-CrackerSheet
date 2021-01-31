#include <bits/stdc++.h>

using namespace std;
//Convert min Heap to max Heap
//Time Complexity := O(n)
//Space Complexity := O(1)
void percolateDown(int *arr, int n, int i)
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
        percolateDown(arr, n, max);
    }
}
void minToMaxHeap(int *arr, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDown(arr, n, i);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    minToMaxHeap(arr, n);
    for (int &i : arr)
        cout << i << " ";
}