#include <iostream>

using namespace std;
// 8.find Largest sum contiguous Subarray [V. IMP]

int maximumSum(int *arr, int n)
{
    int curSum = INT_MIN, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        curSum = (arr[i] > curSum + arr[i]) ? arr[i] : curSum + arr[i];
        maxSum = (curSum > maxSum) ? curSum : maxSum;
    }
    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int &i : arr)
    {
        cin >> i;
    }
    cout << maximumSum(arr, n);
}