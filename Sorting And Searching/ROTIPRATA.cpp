#include <bits/stdc++.h>

using namespace std;
// 117. ROTI PRATA

bool isPossible(vector<int> chef, int pratas, int time)
{
    int n = chef.size();
    int pratasMade = 0;
    for (int i = 0; i < n; i++)
    {
        pratasMade += (-1 + sqrt(1.0 + 8 * time / chef[i])) / 2.0;
        if (pratasMade >= pratas)
            return true;
    }
    return false;
}

int time(vector<int> chef, int pratas)
{
    int n = chef.size();
    int low = 0, high = 4 * (pratas * pratas + pratas);
    int ans = INT32_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(chef, pratas, mid))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    int t, n, pratas;
    cin >> t;
    while (t--)
    {
        cin >> pratas;
        cin >> n;
        vector<int> chef(n);
        for (int &i : chef)
            cin >> i;
        sort(chef.begin(), chef.end());
        cout << time(chef, pratas) << "\n";
    }
}