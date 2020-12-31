#include <bits/stdc++.h>

using namespace std;
//113. Weighted Job Scheduling in O(n Log n) time

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.first.second <= b.first.second;
}
//recursive Solution
//Time : O(n*(2^n))
int lastNonConflicting(vector<pair<pair<int, int>, int>> &schedule, int i)
{
    for (int j = i - 2; j >= 0; j--)
    {
        if (schedule[j].first.second <= schedule[i - 1].first.first)
            return j;
    }
    return -1;
}
int maxProfit(vector<pair<pair<int, int>, int>> &schedule, int n)
{
    if (n == 1)
        return schedule[n - 1].second;
    int inclProfit = schedule[n - 1].second;
    int i = lastNonConflicting(schedule, n);
    if (i != -1)
        inclProfit += maxProfit(schedule, i + 1);
    int exlProfit = maxProfit(schedule, n - 1);
    return (exlProfit > inclProfit) ? exlProfit : inclProfit;
}

//BinarySearch + Dynamic Programming Solution
//Time : O(n*logn)

int binarySearch(vector<pair<pair<int, int>, int>> schedule, int n)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (schedule[mid].first.second <= schedule[n].first.first)
        {
            if (schedule[mid + 1].first.second <= schedule[n].first.first)
                low = mid + 1;
            else
                return mid;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int maxProfit(vector<pair<pair<int, int>, int>> schedule)
{
    int n = schedule.size();
    vector<int> dp(n, 0);
    dp[0] = schedule[0].second;
    for (int i = 1; i < n; ++i)
    {
        int inclProfit = schedule[i].second;
        int l = binarySearch(schedule, i);
        if (l != -1)
            inclProfit += dp[l];
        dp[i] = max(dp[i - 1], inclProfit);
    }
    return dp[n - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> schedule(n);
    for (auto &i : schedule)
        cin >> i.first.first >> i.first.second >> i.second;
    sort(schedule.begin(), schedule.end(), compare);
    cout << maxProfit(schedule);
}