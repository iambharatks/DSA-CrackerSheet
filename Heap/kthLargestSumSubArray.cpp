#include <bits/stdc++.h>

using namespace std;
// K-th Largest Sum Contiguous Subarray
//Implemented Priority Queue
//Time Complexity := O(n*logk)
//Space Complexity := O(k)
template <typename T>
class priorityQueue
{
    T *arr;
    int capacity;
    bool (&cmp)(T a, T b);

public:
    int size;
    priorityQueue(bool (&comparator)(T a, T b)) : arr(new T[1]), size(0), capacity(1), cmp(comparator) {}
    void resizePriorityQueue()
    {
        T *oldArr = arr;
        capacity *= 2;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = oldArr[i];
        delete oldArr;
    }
    int parent(int i) { return (i - 1) / 2; }
    void push(T newElement)
    {
        if (size == capacity)
            resizePriorityQueue();
        size++;
        int i = size - 1;
        while (i > 0 && cmp(newElement, arr[parent(i)]))
        {
            arr[i] = arr[parent(i)];
            i = parent(i);
        }
        arr[i] = newElement;
    }
    int leftChild(int i)
    {
        int left = 2 * i + 1;
        if (left >= size)
            return -1;
        return left;
    }
    //O(1)
    int rightChild(int i)
    {
        int right = 2 * i + 2;
        if (right >= size)
            return -1;
        return right;
    }
    void percolateDown(int i)
    {
        if (i >= size)
            return;
        int left = leftChild(i);
        int right = rightChild(i);
        int max;
        if (left != -1 && cmp(arr[left], arr[i]))
            max = left;
        else
            max = i;
        if (right != -1 && cmp(arr[right], arr[max]))
            max = right;
        if (max != i)
        {
            T tmp = arr[i];
            arr[i] = arr[max];
            arr[max] = tmp;
            percolateDown(max);
        }
    }
    T front()
    {
        if (size == 0)
            return INT_MIN;
        return arr[0];
    }
    T pop()
    {
        T max;
        if (size == 0)
            return -1;
        max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        percolateDown(0);
        return max;
    }
    void print()
    {
        if (size == 0)
            cout << "Empty Heap";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << '\n';
    }
};
bool minHeap(int a, int b) { return a < b; }
int kthLargestSum(int *arr, int n, int k)
{
    priorityQueue<int> pq(minHeap);
    int sum[n + 1];
    sum[0] = 0;
    sum[1] = arr[0];
    for (int i = 2; i <= n; i++)
        sum[i] = sum[i - 1] + arr[i - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int subarraySum = sum[j] - sum[i - 1];
            cout << subarraySum << " ";
            if (pq.size < k)
                pq.push(subarraySum);
            else
            {
                if (pq.front() < subarraySum)
                {
                    pq.pop();
                    pq.push(subarraySum);
                }
            }
        }
    }
    return pq.front();
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    cout << kthLargestSum(arr, n, k);
}