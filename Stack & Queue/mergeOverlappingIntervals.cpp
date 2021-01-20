#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.first <= b.first; }

void overlappedIntervals(vector<pair<int, int>> vec)
{
    int n = vec.size();
    int index = 0;
    sort(vec.begin(), vec.end(), compare);
    for (int i = 1; i < n; ++i)
    {
        if (vec[index].second >= vec[i].first)
        {
            vec[index].first = min(vec[index].first, vec[i].first);
            vec[index].second = max(vec[index].second, vec[i].second);
        }
        else
        {
            index++;
            vec[index] = vec[i];
        }
    }
    for (int i = 0; i <= index; i++)
        cout << vec[i].first << " " << vec[i].second << " ";
    cout << "\n";
}

void mergedOverlappedIntervals(vector<pair<int, int>> vec)
{
    int n = vec.size();
    int index = 0;
    sort(vec.begin(), vec.end(), compare);
    stack<pair<int, int>> s;
    s.push(vec[0]);
    for (int i = 1; i < n; ++i)
    {
        pair<int, int> top = s.top();
        if (top.second < vec[i].first)
            s.push(vec[i]);
        else if (top.second < vec[i].second)
        {
            top.second = vec[i].second;
            s.pop();
            s.push(top);
        }
    }
    while (!s.empty())
    {
        cout << s.top().first << " " << s.top().second << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for (auto &i : vec)
        cin >> i.first >> i.second;
    mergedOverlappedIntervals(vec);
}