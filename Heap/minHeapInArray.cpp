#include <bits/stdc++.h>

using namespace std;
bool minHeap(int a, int b)
{
    return a < b;
}
bool maxHeap(int a, int b)
{
    return a > b;
}
void percolateDown(int *arr, int n, int i, bool (&cmp)(int a, int b))
{
    if (i >= n)
        return;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int min;
    if (left < n && cmp(arr[left], arr[i]))
        min = left;
    else
        min = i;
    if (right < n && cmp(arr[right], arr[min]))
        min = right;
    if (min != i)
    {
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
        percolateDown(arr, n, min, cmp);
    }
}

void heapify(int *arr, int n, bool (&cmp)(int a, int b))
{
    for (int i = (n - 1) / 2; i >= 0; i--)
        percolateDown(arr, n, i, cmp);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    heapify(arr, n, maxHeap);
    for (int &i : arr)
        cout << i << " ";
}