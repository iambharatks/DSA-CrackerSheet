#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//9. Minimise the maximum difference between heights [V.IMP]
int getMinDiff(int arr[], int n, int k)
{
    vector<pair<int, int>> v;
    vector<int> taken(n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] - k >= 0)
        {
            v.push_back({arr[i] - k, i});
        }
        v.push_back({arr[i] + k, i});
    }
    sort(v.begin(), v.end());
    int elements_in_range = 0;
    int left = 0;
    int right = 0;

    while (elements_in_range < n && right < v.size())
    {
        if (taken[v[right].second] == 0)
        {
            elements_in_range++;
        }
        taken[v[right].second]++;
        right++;
    }
    int ans = v[right - 1].first - v[left].first;
    while (right < v.size())
    {
        if (taken[v[left].second] == 1)
        {
            elements_in_range--;
        }
        taken[v[left].second]--;
        left++;

        while (elements_in_range < n && right < v.size())
        {
            if (taken[v[right].second] == 0)
            {
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }

        if (elements_in_range == n)
        {
            ans = min(ans, v[right - 1].first - v[left].first);
        }
        else
        {
            break;
        }
    }
    return ans;
}
int minDif(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int small = arr[0] + k;
    int big = arr[n - 1] - k;
    int ans = arr[n - 1] - arr[0];
    if (small > big)
        swap(small, big);
    for (int i = 1; i < n - 1; i++)
    {
        int subt = arr[i] - k;
        int add = arr[i] + k;
        if (add <= big && subt >= small)
            continue;
        if (big - add < small - subt)
            big = add;
        else
            small = subt;
        ans = min(ans, big - small);
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n] = {0};
    int min = INT_MAX, max = 0;
    for (int &i : arr)
        cin >> i;
    cout << getMinDiff(arr, n, k) << "\n";
    return 0;
}