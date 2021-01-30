#include <bits/stdc++.h>

using namespace std;
#define N 105
//Brilliant approach
//Time complexity := O(n*k*logk)
//Space complexity := O(n*k*logk)
void merge(int *a1, int *a2, int n1, int n2, int *a)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
            a[k++] = a1[i++];
        else
            a[k++] = a2[j++];
    }
    while (i < n1)
        a[k++] = a1[i++];
    while (j < n2)
        a[k++] = a2[j++];
}

void mergeKArrays(int A[][N], int i, int j, int k, int output[])
{
    if (i == j)
    {
        for (int l = 0; l < k; l++)
            output[l] = A[i][l];
        return;
    }
    if (j - i == 1)
    {
        merge(A[i], A[j], k, k, output);
        return;
    }
    int n1 = k * ((i + j) / 2 - i + 1), n2 = k * (j - (i + j) / 2);
    int output1[n1], output2[n2];
    mergeKArrays(A, i, (i + j) / 2, k, output1);
    mergeKArrays(A, (i + j) / 2 + 1, j, k, output2);
    merge(output1, output2, n1, n2, output);
}
int *mergeKArrays(int arr[][N], int k)
{
    int *output = new int[k * k];
    mergeKArrays(arr, 0, k - 1, k, output);
    return output;
}

//..............................................................................................................
//Method 2....
//using minheap
bool minHeap(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first < b.first; }
bool maxHeap(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first > b.first; }
template <typename T>
class heap
{
    T *arr;
    int size;
    int capacity;
    bool (&cmp)(T a, T b);

public:
    heap(bool (&comparator)(T a, T b)) : arr(new T[1]), capacity(1), size(0), cmp(comparator) {}
    void resizeHeap()
    {
        T *oldArray = arr;
        arr = new T[capacity * 2];
        for (int i = 0; i < size; i++)
            arr[i] = oldArray[i];
        delete oldArray;
        capacity *= 2;
    }
    //O(1)
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
    //O(1)
    int parent(int i)
    {
        if (i > 0)
            return (i - 1) / 2;
        return -1;
    }
    //correcting our heap structure
    //by swapping the node with greater of the left or right child
    //tail ended recursion
    //Time Complexity := O(logn)
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
    //swap with last element and
    // percolate down from there
    //Time Complexity := O(logn)
    T popMin()
    {
        T max;
        if (size == 0)
            return {INT_MIN, {-1, -1}};
        max = arr[0];
        arr[0] = arr[size - 1];
        size--;
        percolateDown(0);
        return max;
    }
    //percolate up
    //compare it with parent
    //if newElement is greater than move parent down
    //otherwise newElement becomes child
    //O(logn)
    void insert(T newElement)
    {
        if (size == capacity)
            resizeHeap();
        size++;
        int i = size - 1;
        while (i > 0 && cmp(newElement, arr[parent(i)]))
        {
            arr[i] = arr[parent(i)];
            i = parent(i);
        }
        arr[i] = newElement;
    }
    //delete Heap
    void deleteHeap()
    {
        if (size == 0)
            return;
        free(arr);
        size = 0;
    }
    //heapify the array
    //O(n) see notes why?
    void make_heap(T *A, int n)
    {
        while (capacity < n)
            resizeHeap();
        for (int i = 0; i < n; i++)
            arr[i] = A[i];
        size = n;
        //percolate down from last non leaf node to root
        //this is O(n)
        //although looks O(nlogn)
        for (int i = (n - 1) / 2; i >= 0; i--)
            percolateDown(i);
        for (int i = 0; i < n; i++)
            A[i] = arr[i];
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
//pair.first == value
//pair.second.first == ith array
//pair.second.second == index of ith array to pick element from next
int *mergeKsorted(int A[][N], int k)
{
    heap<pair<int, pair<int, int>>> min(minHeap);
    int *output = new int[k * k];
    for (int i = 0; i < k; i++)
        min.insert({A[i][0], {i, 1}});
    for (int i = 0; i < k * k; i++)
    {
        pair<int, pair<int, int>> element = min.popMin();
        if (element.second.second != -1)
            output[i] = element.first;
        if (element.second.second < k)
            element.first = A[element.second.first][element.second.second];
        else
            element.first = INT_MAX;
        element.second.second += 1;
        min.insert(element);
    }
    return output;
}

int main()
{
    int k;
    cin >> k;
    int arr[k][N];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            cin >> arr[i][j];
    int *merged = mergeKsorted(arr, k);
    for (int i = 0; i < k * k; i++)
        cout << merged[i] << " ";
}