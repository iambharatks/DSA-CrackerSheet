#include <bits/stdc++.h>

using namespace std;

//52.Longest Palindrome in a String

void reverse(string &s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
        swap(s[l++], s[r--]);
}

string naiveApproach(string s)
{
    string rev = s;
    reverse(rev);
    int n = s.size();
    int len = 0;
    string ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= n - i; ++j)
        {
            string t1 = s.substr(i, j);
            string t2 = rev.substr(n - j - i, j);
            // cout << t1 << " " << t2 << "\n";
            if (t1 == t2 && len < j)
            {
                len = j;
                ans = t1;
            }
        }
    }
    return ans;
}
// Time : = O(n*n)
//Space := O(n*n)
string dynamicApproch(string s)
{
    int n = s.size();
    bool table[n][n];
    for (int i = 0; i < n; i++)
        memset(table[i], 0, n);
    int maxLength = 1;
    int start = 0;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
    for (int i = 0; i < n - 1; ++i)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            maxLength = 2;
            start = i;
        }
    }
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i <= n - k; i++)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && s[i] == s[j])
            {
                table[i][j] = true;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    return s.substr(start, maxLength);
}
// Time := O(n*n)
//Space := O(1)
string optimal(string s)
{
    int maxLength = 1;
    int start = 0;
    int len = s.size();
    int low, high;
    for (int i = 1; i < len; ++i)
    {
        low = i - 1, high = i;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1, high = i + 1;
        while (low >= 0 && high < len && s[low] == s[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
    return s.substr(start, maxLength);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << optimal(s) << "\n";
    }
}