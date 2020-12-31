#include <bits/stdc++.h>

using namespace std;
//17. Count pairs with given sum
int m[1000001];
int getPairsCount(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum - arr[i] >= 0)
        {
            cnt += m[sum - arr[i]];
            if (arr[i] == sum - arr[i])
                --cnt;
        }
    }
    return cnt / 2;
}
int main()
{
    int N, K;
    cin >> N >> K;
    int arr[N];
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cout << getPairsCount(arr, N, K);
}