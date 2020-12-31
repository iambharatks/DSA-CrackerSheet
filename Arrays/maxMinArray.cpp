#include <iostream>

using namespace std;
//2.Find the maximum and minimum element in an array
int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    int _max = INT_MIN, _min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        _max = max(_max, arr[i]);
        _min = min(_min, arr[i]);
    }
    cout << _max << " " << _min << "\n";
}