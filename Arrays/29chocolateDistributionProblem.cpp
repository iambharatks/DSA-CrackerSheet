#include <bits/stdc++.h>

using namespace std;
//29. Chocolate Distribution Problem
int slidingWindow(vector<int> chocolates, int m)
{
    int n = chocolates.size();
    sort(chocolates.begin(), chocolates.end());
    int ans = INT_MAX;
    for (int i = 0; i <= n - m; i++)
        ans = min(ans, chocolates[i + m - 1] - chocolates[i]);
    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> chocolates(n);
        for (int &i : chocolates)
            cin >> i;
        cout << slidingWindow(chocolates, m) << "\n";
    }
}