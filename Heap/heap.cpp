#include <bits/stdc++.h>

using namespace std;

//maxHeap
template <typename T>
class heap
{
    T *arr;
    int size;
    int capacity;

public:
    heap() : arr(new int[1]), capacity(1), size(0) {}
    void resizeHeap()
    {
        T *oldArray = arr;
        arr = new int[capacity * 2];
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
    //O(1)
    T getMax()
    {
        if (size == 0)
            return -1;
        return arr[0];
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
        if (left != -1 && arr[left] > arr[i])
            max = left;
        else
            max = i;
        if (right != -1 && arr[right] > arr[max])
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
    T deleteMax()
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
        while (i > 0 && newElement > arr[(i - 1) / 2])
        {
            arr[i] = arr[(i - 1) / 2];
            i = (i - 1) / 2;
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
        A = arr;
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

int main()
{
    int choice = 1, data, pos;
    heap<int> h;
    while (choice)
    {
        cout << "Select your choice\n\t1.insert\n\t2.get Max\n\t3.pop max\n\t4.left child\n\t5.right child\n\t0.Quite\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> data;
            h.insert(data);
            break;
        case 2:
            cout << h.getMax() << "\n";
            break;
        case 3:
            cout << h.deleteMax() << "\n";
            break;
        case 4:
            cin >> pos;
            cout << h.leftChild(pos) << "\n";
            break;
        case 5:
            cin >> pos;
            cout << h.rightChild(pos) << "\n";
            break;
        case 0:
            cout << "Thankyou\n";
            break;
        }
        cout << "Heap := ";
        h.print();
    }
}