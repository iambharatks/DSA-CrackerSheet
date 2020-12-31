#include <bits/stdc++.h>

using namespace std;

int minMaxDiff(int arr[], int n, int k)
{
    int max_adj_dif = INT_MIN;
    for (int i = 0; i < n - 1; i++)
        max_adj_dif = max(max_adj_dif, abs(arr[i] - arr[i + 1]));
    if (max_adj_dif == 0)
        return 0;
    int best = 1;
    int worst = max_adj_dif;
    int mid, required;

    while (best < worst)
    {
        mid = (best + worst) / 2;
        required = 0;
        for (int i = 0; i < n - 1; i++)
        {

            required += (abs(arr[i] - arr[i + 1]) - 1) / mid;
        }
        if (required > k)
            best = mid + 1;
        else
            worst = mid;
    }

    return worst;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int a[n];
        for (int &i : a)
            cin >> i;
        cin >> k;
        cout << minMaxDiff(a, n, k) << endl;
    }
}