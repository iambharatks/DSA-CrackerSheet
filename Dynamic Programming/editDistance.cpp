#include <bits/stdc++.h>

using namespace std;

// Edit Distance 

int minimum(int i, int j, int k) { return min(i, min(j, k)); }

class recursion
{
public:
    int editDistanceUtil(string &s, string &t, int i, int j)
    {
        if (i == 0)
            return j;
        if (j == 0)
            return i;
        cout << s[i - 1] << " " << t[j - 1] << "\n";
        if (s[i - 1] == t[j - 1])
            return editDistanceUtil(s, t, i - 1, j - 1);
        int ins = editDistanceUtil(s, t, i, j - 1);
        int rem = editDistanceUtil(s, t, i - 1, j);
        int rep = editDistanceUtil(s, t, i - 1, j - 1);
        return minimum(ins, rem, rep) + 1;
    }
    int editDistance(string s, string t)
    {
        return editDistanceUtil(s, t, s.size(), t.size());
    }
};

class memoization
{
public:
    int editDistanceUtil(string s, string t, int i, int j, vector<vector<int>> &table)
    {
        if (i >= s.size())
            return t.size() - j;
        if (j >= t.size())
            return s.size() - i;
        cout << s[i] << " " << t[j] << "\n";

        if (table[i][j] != -1)
            return table[i][j];

        if (s[i] == t[j])
            return table[i][j] = editDistanceUtil(s, t, i + 1, j + 1, table);
        int ins = editDistanceUtil(s, t, i, j + 1, table);
        int rem = editDistanceUtil(s, t, i + 1, j, table);
        int rep = editDistanceUtil(s, t, i + 1, j + 1, table);
        return table[i][j] = minimum(ins, rem, rep) + 1;
    }
    int editDistance(string s, string t)
    {
        vector<vector<int>> table(s.size(), vector<int>(t.size(), -1));
        return editDistanceUtil(s, t, 0, 0, table);
    }
};

class tabulation
{
public:
    int editDistance(string s, string t)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        for (int i = 0; i <= s.size(); i++)
        {
            for (int j = 0; j <= t.size(); j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s[i-1] == t[j-1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = minimum(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[s.size()][t.size()];
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    cout << tabulation().editDistance(s, t);
}