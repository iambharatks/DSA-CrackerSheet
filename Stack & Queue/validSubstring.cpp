#include <bits/stdc++.h>

using namespace std;

//with stack
//Time complexity : O(n)
//Space complexity : O(n)
int findMaxLen(string s)
{
    stack<int> bracks;
    bracks.push(-1);
    int maxLen = 0;
    for (size_t idx = 0; idx < s.size(); idx++)
    {
        if (s[idx] == '(')
            bracks.push(idx);
        else
        {
            if (!bracks.empty())
                bracks.pop();
            if (bracks.empty())
                bracks.push(idx);
            else
                maxLen = (maxLen < idx - bracks.top()) ? idx - bracks.top() : maxLen;
        }
    }
    return maxLen;
}

//Best Approach
//Time Complexity : O(n)
//Space := O(1)
//just keep a counter of openeing and closing
// while traversing from left to right and right to left.

int findMax(string s)
{
    int left = 0, right = 0, maxLen = 0;
    for (char c : s)
    {
        if (c == '(')
            left++;
        else
            right++;
        if (left == right)
            maxLen = max(maxLen, 2 * right);
        if (left < right)
            left = right = 0;
    }
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == '(')
            left++;
        else
            right++;
        if (left == right)
            maxLen = max(maxLen, 2 * left);
        if (left > right)
            left = right = 0;
    }
    return maxLen;
}

//array Approach
//Time complexity : O(n)
//Space complexity : O(n)
//array will store the length of valid substring ending at that index i
int findMaxUsingArray(string s)
{
    vector<int> longest(s.size(), 0);
    int maxLen = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ')' && i - longest[i - 1] - 1 >= 0 && s[i - longest[i - 1] - 1] == '(')
        {
            longest[i] = longest[i - 1] + 2 +
                         ((i - longest[i - 1] - 2 >= 0)
                              ? longest[i - longest[i - 1] - 2]
                              : 0);
            maxLen = max(longest[i], maxLen);
        }
    }
    return maxLen;
}

int main()
{
    string s;
    cin >> s;
    cout << findMaxUsingArray(s);
}