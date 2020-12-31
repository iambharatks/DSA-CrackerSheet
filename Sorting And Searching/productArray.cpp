#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//102. Product array puzzle

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    vector<ll> ans(n);
    ll prod = 1;
    ll nz = 0;
    for (long long i : nums)
    {
        if (i == 0)
            nz++;
        else
            prod *= i;
    }
    if (nz >= 2)
        return ans;
    if (nz == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
                ans[i] = prod;
        }
        return ans;
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = prod / nums[i];
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for (ll &i : A)
        cin >> i;
    vector<ll> ans = productExceptSelf(A, n);
    for (ll i : ans)
        cout << i << " ";
}