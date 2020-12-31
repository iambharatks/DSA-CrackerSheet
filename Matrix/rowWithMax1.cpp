#include <bits/stdc++.h>

using namespace std;
//39. Row with max 1s
//O(n*logm)
int binarySearch(vector<int> arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            if (mid > low && arr[mid - 1] == target)
                high--;
            else
                return mid;
        }
        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return arr.size();
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    int count = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        int cur = m - binarySearch(arr[i], 1);

        if (cur > count)
        {
            count = cur;
            pos = i;
        }
        if (count == m)
            return pos;
    }
    return (count == 0) ? -1 : pos;
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (auto &v : matrix)
    {
        for (int &i : v)
            cin >> i;
    }
    cout << rowWithMax1s(matrix, r, c);
}