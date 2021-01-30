#include <bits/stdc++.h>

using namespace std;
//TODO
//Method 1 would be to use AVL tree
//Have to study AVL trees...
//Time Complexity := O(n*logk)
//Space Complexity := O(k)

//Method 2
//Approach using heap
//Time Complexity := O(n*k)
//Space Complexity := O(k)
void percolateDown(vector<int> &arr, int i, int n)
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
        percolateDown(arr, max, n);
    }
}
int maxInSubarray(vector<int> arr, int start, int end)
{
    for (int i = (end - 1) / 2; i >= start; i--)
        percolateDown(arr, i, end);
    return arr[start];
}
void printKMaxUsingHeap(vector<int> arr, int k)
{
    int n = arr.size();
    for (int i = 0; i <= n - k; i++)
        cout << maxInSubarray(arr, i, i + k) << " ";
    // maxInSubarray(arr, i, i + k);
    cout << "\n";
}
//Method 3
//Using deque
//Time Complexity := O(n)
//Space COmplexity := O(k)
void printKMax(vector<int> arr, int k)
{
    deque<int> Q(k);
    int n = arr.size();
    for (int i = 0; i < k; i++)
    {
        while (!Q.empty() && arr[i] >= arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        cout << arr[Q.front()] << " ";
        while (!Q.empty() && Q.front() <= i - k)
            Q.pop_front();
        while (!Q.empty() && arr[i] >= arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }
    cout << arr[Q.front()] << " ";
    cout << "\n";
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    printKMaxUsingHeap(arr, k);
}