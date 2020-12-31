#include <bits/stdc++.h>

using namespace std;
//12. Merge Intervals

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);
    for (pair<int, int> &i : intervals)
        cin >> i.first >> i.second;
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> soln;
    pair<int, int> current = intervals.front();
    for (int i = 1; i < n; i++)
    {
        if (intervals[i].first <= current.second)
        {
            current.second = (current.second < intervals[i].second) ? intervals[i].second : current.second;
        }
        else
        {
            soln.push_back(current);
            current = intervals[i];
        }
    }
    soln.push_back(current);
    for (auto i : soln)
    {
        cout << i.first << " " << i.second << "\n";
    }
}