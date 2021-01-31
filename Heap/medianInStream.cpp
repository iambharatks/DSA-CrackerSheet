#include <bits/stdc++.h>

using namespace std;
//Find median in a stream
// Method 1
//Time complexity =: O(nlogn)
//For this example
// 10
// 5 15 10 6 3 10 34 12 11 11
// 5             15
//10 5           15
//6 5            10 15
//6 5 3          10 15
//6 5 3          10 10 15
//10 6 5 3       10 15 34
//10 6 5 3       10 12 15 34
//10 10 6 5 3    11 11 12 15 34
class FindMedian
{
public:
    void insertHeap(int &);
    double getMedian();

private:
    double median;                                      //Stores current median
    priority_queue<int> max;                            //Max heap for lower values
    priority_queue<int, vector<int>, greater<int>> min; //Min heap for greater values
    void balanceHeaps();                                //Method used by insertHeap
};
// } Driver Code Ends
// Function to insert heap
void FindMedian::insertHeap(int &x)
{
    // Your code here
    if (max.empty())
        max.push(x);
    else if (median < x)
        min.push(x);
    else
        max.push(x);
    balanceHeaps();
}

// Function to balance heaps
void FindMedian::balanceHeaps()
{
    // Your code here
    int n = max.size() + min.size();
    if (max.size() > min.size() + (n & 1))
    {
        int tmp = max.top();
        max.pop();
        min.push(tmp);
    }
    if (min.size() + (n & 1) > max.size())
    {
        int tmp = min.top();
        min.pop();
        max.push(tmp);
    }
}

// Function to return getMedian
double FindMedian::getMedian()
{
    // Your code here
    int n = max.size() + min.size();
    if (n & 1)
        median = max.top();
    else
        median = (max.top() + min.top()) / 2.0;
    return median;
}
int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        FindMedian Ans;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            Ans.insertHeap(x);
            cout << (Ans.getMedian()) << endl;
        }
    }
}