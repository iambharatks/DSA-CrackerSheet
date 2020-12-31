#include <bits/stdc++.h>

using namespace std;

//99. Count triplets with sum smaller than X
long long countTriplets(vector<long long> arr, long long sum)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    long long cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int low = i + 1;
        int high = n - 1;
        while (low < high)
        {
            if (arr[i] + arr[low] + arr[high] >= sum)
                high--;
            else
            {
                cnt += high - low;
                low++;
                // For current i and j, there
                // can be total k-j third elements.
            }
        }
    }
    return cnt;
}
int main()
{
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (long long &i : a)
        cin >> i;
    cout << countTriplets(a, x);
}