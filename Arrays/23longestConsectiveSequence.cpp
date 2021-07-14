#include <iostream>
#include <vector>
#include <map>

using namespace std;
//23. Longest Consecutive Subsequence
int main()
{
    int n;
    cin >> n;
    int arr[100001] = {0};

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ++arr[x];
    }
    int maxL = 0, curL = 0;
    for (int i = 1; i <= 100000; ++i)
    {
        if (arr[i])
            ++curL;
        else
        {
            maxL = (maxL < curL) ? curL : maxL;
            curL = 0;
        }
    }
    maxL = (maxL < curL) ? curL : maxL;
    cout << maxL;
}