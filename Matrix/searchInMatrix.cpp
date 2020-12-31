#include <bits/stdc++.h>

using namespace std;

//37.Search in Matrix

bool binarySearch(vector<int> a, int target)
{
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        // cout << a[mid] << " ";
        if (a[mid] == target)
            return true;
        if (a[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}
// O(n)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = matrix.size();
    if (r == 0)
        return false;
    int c = matrix[0].size();
    if (c == 0)
        return false;
    int row = 0, column = c - 1;
    while (row < r && column >= 0)
    {
        if (matrix[row][column] == target)
            return true;
        if (matrix[row][column] > target)
            column--;
        else if (matrix[row][column] < target)
            row++;
    }
    return false;
}
//O(logn)
bool search(vector<vector<int>> &matrix, int target)
{
    int left = 0, right = matrix.size() - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (target > matrix[mid].back())
            left = mid + 1;
        else if (target < matrix[mid].front())
            right = mid - 1;
        else
            break;
    }
    int row = mid;
    left = 0, right = matrix[mid].size() - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (matrix[row][mid] == target)
            return true;
        else if (matrix[row][mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}
int main()
{
    int r, c, target;
    cin >> r >> c;

    vector<vector<int>> matrix(r, vector<int>(c));
    for (auto &v : matrix)
    {
        for (int &i : v)
            cin >> i;
    }
    cin >> target;
    cout << search(matrix, target);
}