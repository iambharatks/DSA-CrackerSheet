#include <bits/stdc++.h>

using namespace std;
// 111. Book Allocation Problem

bool isAllocationPossible(int *pages, int n, int totalStudents, int cur_min)
{
    int students = 1;
    int cur_sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cur_min < pages[i])
            return false;
        else if (cur_sum + pages[i] <= cur_min)
        {
            cur_sum += pages[i];
        }
        else
        {
            students++;
            cur_sum = pages[i];
            if (students > totalStudents)
                return false;
        }
    }
    return true;
}

int findPages(int *pages, int n, int totalStudents)
{
    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
        high += pages[i];
    int ans = INT_MAX;
    if (n < totalStudents)
        return -1;
    if (totalStudents == 1)
        return high;
    while (high >= low)
    {
        int mid = (high +   low) / 2;
        if (isAllocationPossible(pages, n, totalStudents, mid))
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
    int n, totalStudents;
    cin >> n;
    int pages[n];
    for (int i = 0; i < n; ++i)
        cin >> pages[i];
    cin >> totalStudents;
    cout << findPages(pages, n, totalStudents);
}