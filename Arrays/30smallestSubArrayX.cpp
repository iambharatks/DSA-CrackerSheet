#include <bits/stdc++.h>

using namespace std;
//30. Smallest subarray with sum greater than x
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        int sum = 0;
        int start = 0, end = 0, ans = n;
        while (end <= n)
        {
            if (sum > x)
            {
                ans = min(end - start, ans);
                sum -= v[start++];
            }
            else
            {
                if (end >= n)
                    break;
                sum += v[end++];
            }
            // cout << sum << " ";
        }
        cout << ans << "\n";
    }
}