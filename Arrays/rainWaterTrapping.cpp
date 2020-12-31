#include <iostream>
#include <vector>

using namespace std;
//28. Trapping Rain Water problem
void withSpace(vector<int> height)
{
    int n = height.size();
    vector<int> l(n, 0), r(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            l[i] = height[i];
            continue;
        }
        l[i] = max(l[i - 1], height[i]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            r[i] = height[i];
            continue;
        }
        r[i] = max(r[i + 1], height[i]);
    }
    int trappedWater = 0;
    for (int i = 0; i < n; i++)
        trappedWater += max(min(l[i], r[i]) - height[i], 0);
    cout << trappedWater << "\n";
}

void optimal(vector<int> h)
{
    int n = h.size();
    int left_max = h[0], right_max = h[n - 1];
    int l = 0, r = n - 1;
    int trappedWater = 0;
    while (l < r)
    {
        if (h[l] < h[r])
        {
            (h[l] >= left_max) ? left_max = h[l] : trappedWater += left_max - h[l];
            l++;
        }
        else
        {
            (h[r] >= right_max) ? right_max = h[r] : trappedWater += right_max - h[r];
            r--;
        }
    }
    cout << trappedWater << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> height(n);
        for (int &i : height)
            cin >> i;
        withSpace(height);
        optimal(height);
    }
}