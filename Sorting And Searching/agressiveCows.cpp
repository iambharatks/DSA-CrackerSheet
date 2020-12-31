#include <bits/stdc++.h>

using namespace std;
// 110.AGGRCOW - Aggressive cows

bool possible(vector<int> stall, int totalCows, int dist)
{
    int n = stall.size();
    int pos = stall[0];
    int cows = 1;
    for (int i = 1; i < n; i++)
    {
        if (stall[i] - pos >= dist)
        {
            pos = stall[i];
            cows++;
        }
        if (cows == totalCows)
            return true;
    }
    return false;
}

int binarySearch(vector<int> stall, int cows)
{
    int n = stall.size();
    int L = 0, R = stall[n - 1];
    int maxDist = 0;
    while (L <= R)
    {
        int mid = L + (R - L) / 2;
        if (possible(stall, cows, mid))
        {
            maxDist = (mid > maxDist) ? mid : maxDist;
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    return maxDist;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, cows;
        cin >> n >> cows;
        vector<int> stall(n);
        for (int &i : stall)
            cin >> i;
        sort(stall.begin(), stall.end());
        cout << binarySearch(stall, cows) << "\n";
    }
}