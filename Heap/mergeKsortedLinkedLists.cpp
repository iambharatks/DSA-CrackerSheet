#include <bits/stdc++.h>

using namespace std;

// Merged K Sorted Linked Lists using Heap
//Time Complexity := O(N*logN)
//Space Complexity := O(N)

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
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
        T tp;
        if (size == 0)
            return tp;
        return arr[0];
    }
    T pop()
    {
        T max;
        if (size == 0)
            return max;
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
bool minHeap(Node *a, Node *b) { return a->data < b->data; }

Node *mergeKLists(Node *arr[], int N)
{
    Node *merged = NULL, *prev;
    priorityQueue<Node *> pq(minHeap);
    for (int i = 0; i < N; ++i)
    {
        if (arr[i])
            pq.push(arr[i]);
        else
        {
            Node *tmp = new Node(INT_MAX);
            pq.push(tmp);
        }
    }
    while (pq.front()->data != INT_MAX)
    {
        Node *tmp = pq.pop();
        if (merged == NULL)
            merged = tmp;
        else
            prev->next = tmp;
        prev = tmp;
        tmp = tmp->next;
        if (tmp)
            pq.push(tmp);
        else
        {
            Node *tmp = new Node(INT_MAX);
            pq.push(tmp);
        }
    }
    return merged;
}

int main()
{
}