#include <bits/stdc++.h>

using namespace std;

//Naive Approach
//Time complexity : O(n*n)
//Space complexity : O(n)
long long getMaxAreaN(long long arr[], int n)
{
    int cnt = 0;
    vector<pair<long long, long long>> maxH;
    maxH.push_back({arr[0], 0});
    long long maxArea = arr[0];
    for (int i = 1; i < n; ++i)
    {
        for (auto &curH : maxH)
        {
            if (curH.first > arr[i])
                curH.first = arr[i];
            maxArea = max(maxArea, curH.first * (i - curH.second + 1));
            cnt++;
        }
        if (maxH.back().first < arr[i])
        {
            maxH.push_back({arr[i], i});
            maxArea = max(maxArea, arr[i]);
        }
    }
    // for (auto i : maxH)
    // cout << i.first << " " << i.second << "\n";
    // cout << n << " --> " << cnt << "\n";
    return maxArea;
}

//TODO:=
//You can do it using segment tree in O(nlogn)
//Divide And Conquer

//Approach using stack
//Time complexity := O(n)
//Space := O(n)
long long getMaxArea(long long arr[], int n)
{
    stack<int> s;
    long long maxArea = 0, area_with_top;
    int topIdx, idx = 0;
    while (idx < n)
    {
        if (s.empty() || arr[s.top()] <= arr[idx])
            s.push(idx++);
        else
        {
            topIdx = s.top();
            s.pop();
            area_with_top = arr[topIdx] * (s.empty() ? idx : (idx - s.top() - 1));
            maxArea = (maxArea > area_with_top) ? maxArea : area_with_top;
        }
    }
    while (!s.empty())
    {
        topIdx = s.top();
        s.pop();
        area_with_top = arr[topIdx] * (s.empty() ? idx : idx - s.top() - 1);
        maxArea = (maxArea > area_with_top) ? maxArea : area_with_top;
    }
    return maxArea;
}
int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (auto &i : arr)
        cin >> i;
    cout << getMaxArea(arr, n);
}