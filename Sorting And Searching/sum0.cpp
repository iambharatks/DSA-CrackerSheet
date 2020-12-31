#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//101.Zero Sum Subarrays

ll findSubarray(vector<ll> arr, int n)
{
    vector<ll> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + arr[i - 1];
    // for (int i = 1; i <= n; i++)
        // cout << pref[i] << " ";
    // cout << endl;
    ll cnt = 0;
    unordered_map<long long, long long> present;
    for (int i = 1; i <= n; i++)
    {
        if (pref[i] == 0)
            cnt++;
        if (present[pref[i]])
        {
            cnt += present[pref[i]];
            present[pref[i]]++;
        }
        else
        {
            present[pref[i]]++;
        }
    }
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> A(n);
    for (long long &i : A)
        cin >> i;
    cout << findSubarray(A, n);
}
