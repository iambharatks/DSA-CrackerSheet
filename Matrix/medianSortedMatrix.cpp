#include <bits/stdc++.h>

using namespace std;
//! matrix is sorted row wise only
class Solution
{
public:
    int upperBound(vector<int> arr, int key)
    {
        int low = 0, high = arr.size() - 1;
        int idx = high + 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (arr[mid] > key)
            {
                idx = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return idx;
    }
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int min = matrix[0][0];
        int max = matrix[0][c - 1];
        for (int i = 0; i < r; i++)
        {
            min = (min > matrix[i][0]) ? matrix[i][0] : min;
            max = (max < matrix[i][c - 1]) ? matrix[i][c - 1] : max;
        }
        int desired = (r * c + 1) / 2;
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            int lessThanMid = 0;
            for (int i = 0; i < r; ++i)
                lessThanMid += upperBound(matrix[i], mid);
            if (lessThanMid < desired)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));
    for (auto &v : mat)
        for (auto &i : v)
            cin >> i;
    cout << Solution().median(mat, n, m);
}