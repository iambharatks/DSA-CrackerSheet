#include <bits/stdc++.h>

using namespace std;
//Time Complexity := O(nlogn)
//Space Complexity := O(1)
//inplace sorting
bool minHeap(int a, int b) { return a < b; }
bool maxHeap(int a, int b) { return a > b; }
void percolateDown(int arr[], int n, int i, bool (&cmp)(int a, int b))
{
    if (i >= n)
        return;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max;
    if (left < n && cmp(arr[left], arr[i]))
        max = left;
    else
        max = i;
    if (right < n && cmp(arr[right], arr[max]))
        max = right;
    if (max != i)
    {
        int tmp = arr[i];
        arr[i] = arr[max];
        arr[max] = tmp;
        percolateDown(arr, n, max, cmp);
    }
}
//O(nlogn)
void heapSort(int *arr, int n, bool (&cmp)(int a, int b))
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDown(arr, n, i, cmp);
    //swapping maximum element with last
    //and reducing the size of heap by 1
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        percolateDown(arr, i, 0, cmp);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    heapSort(arr, n - 5, minHeap);
    heapSort(arr, n, maxHeap);
    for (int &i : arr)
        cout << i << " ";
}