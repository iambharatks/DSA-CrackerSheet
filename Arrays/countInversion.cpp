#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;
//15. Count Inversions
int merge(vector<int> arr, vector<int> temp, int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv_count += mid - i;
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; ++i)
        arr[i] = temp[i];
    return inv_count;
}

int mergeSort(vector<int> arr, vector<int> temp, int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = left + (right - left) / 2;
        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int inversionCount(vector<int> arr)
{
    vector<int> temp(arr.size());
    return mergeSort(arr, temp, 0, arr.size() - 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    cout << inversionCount(a) << "\n";
}