#include <bits/stdc++.h>

using namespace std;
#define ll long long
//22.Find Maximum Product Subarray

int maximumProduct(vector<ll> a)
{
    ll minVal = a[0], maxVal = a[0], maxProd = a[0];
    int n = a.size();
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < 0)
            swap(minVal, maxVal);
        minVal = min(a[i], minVal * a[i]);
        maxVal = max(a[i], maxVal * a[i]);
        cout << minVal << " " << maxVal << "\n";
        maxProd = max(maxProd, maxVal);
    }
    return maxProd;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;
    cout << maximumProduct(a) << "\n";
}