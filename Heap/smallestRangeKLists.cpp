#include <bits/stdc++.h>

using namespace std;
#define N 1000
//i though of this approach too Approach
//Time Complexity := O(nlogk)
//Space complexity := O(k)
void print(set<pair<int, pair<int, int>>> s)
{
    for (auto it = s.begin(); it != s.end(); it++)
        cout << "(" << it->first << " " << it->second.first << " " << it->second.second << ") ";
    cout << '\n';
}
pair<int, int> findSmallestRange(int arr[][N], int n, int k)
{
    set<pair<int, pair<int, int>>> s;
    for (int i = 0; i < k; i++)
        s.insert({arr[i][0], {i, 1}});
    print(s);
    pair<int, int> ans = {0, 0};
    while (!s.empty() && s.rbegin()->first != INT_MAX)
    {
        pair<int, pair<int, int>> tmp = *(s.begin());
        int last = s.rbegin()->first;
        if (ans.first == 0 && ans.second == 0)
            ans = {tmp.first, last};
        else if (last - tmp.first < ans.second - ans.first)
            ans = {tmp.first, last};
        if (tmp.second.second < n)
            tmp.first = arr[tmp.second.first][tmp.second.second];
        else
            tmp.first = INT_MAX;
        s.erase(s.begin());
        tmp.second.second += 1;
        s.insert(tmp);
        print(s);
    }
    return ans;
}

//Using priority Queue
bool minHeap(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) { return a.first < b.first; }

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
pair<int, int> smallestRange(int arr[][N], int n, int k)
{
    priorityQueue<pair<int, pair<int, int>>> pq(minHeap);
    pair<int, int> range;
    int minRange = INT_MAX;
    int max = INT_MIN, min = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        pq.push({arr[i][0], {i, 1}});
        if (max < arr[i][0])
            max = arr[i][0];
    }
    while (true)
    {
        pair<int, pair<int, int>> tmp = pq.pop();
        min = tmp.first;
        if (minRange > max - min + 1)
        {
            minRange = max - min + 1;
            range.first = min;
            range.second = max;
        }
        if (tmp.second.second < n)
        {
            tmp.first = arr[tmp.second.first][tmp.second.second];
            tmp.second.second += 1;
            if (tmp.first > max)
                max = tmp.first;
        }
        else
            break;
        pq.push(tmp);
    }
    return range;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[N][N];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    pair<int, int> ans = smallestRange(arr, n, k);
    cout << ans.first << " " << ans.second;
}