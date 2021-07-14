#include <iostream>
#include <algorithm>

using namespace std;
//3.Find the "Kth" max and min element of an array 
//1 <= k <= n
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n] = {0};
    int _max = INT_MIN, _min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    _max = arr[n - k];
    _min = arr[k - 1];
    cout << _max << " " << _min << "\n";
}