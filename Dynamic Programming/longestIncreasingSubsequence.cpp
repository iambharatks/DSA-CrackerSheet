#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

class tabulation
{
    vector<int> dp;
    vector<int> prev;

public:
    int longestSubsequence(int n, int a[])
    {
        dp.resize(n, 1);
        prev.resize(n, -1);
        int i, j, ans = 1, end;
        for (i = 1; i < n; i++)
        {
            j = i - 1;
            while (j >= 0)
            {
                if (a[j] < a[i])
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
                j--;
            }
            if (ans < dp[i])
            {
                ans = dp[i];
                end = i;
            }
        }
        for (int i = end; i != -1; i = prev[i])
            cout << a[i] << " ";
        cout << '\n';
        return ans;
    }
};

int main()
{
    int n;
    int a[N];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << tabulation().longestSubsequence(n, a);
}