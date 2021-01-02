#include <bits/stdc++.h>

using namespace std;

//1. N meetings in one room
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    if (a.first.second != b.first.second)
        return a.first.second <= b.first.second;
    return a.second <= b.second;
}
void maxMeetings(int start[], int end[], int n)
{
    // Your code here
    vector<pair<pair<int, int>, int>> meeting(n);
    for (int i = 0; i < n; i++)
        meeting[i] = {{start[i], end[i]}, i + 1};
    sort(meeting.begin(), meeting.end(), compare);
    pair<int, int> prev;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prev = {meeting[i].first.first, meeting[i].first.second};
            cout << meeting[i].second << " ";
        }
        if (prev.second < meeting[i].first.first)
        {
            prev = {meeting[i].first.first, meeting[i].first.second};
            cout << meeting[i].second << " ";
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int start[n], end[n];
    for (int i = 0; i < n; i++)
        cin >> start[i];
    for (int i = 0; i < n; i++)
        cin >> end[i];
    maxMeetings(start, end, n);
}