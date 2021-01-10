#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void removeInvalidParentheses(string s, vector<string> &soln, int pos = 0, string ans = "", int valid = 0)
    {
        if (pos == s.size() && valid == 0)
        {
            soln.push_back(ans);
            return;
        }
        if (pos > s.size())
            return;
        if (s[pos] == '(')
        {
            removeInvalidParentheses(s, soln, pos + 1, ans + s[pos], valid + 1);
        }
        else if (s[pos] == ')')
        {
            if (valid > 0)
                removeInvalidParentheses(s, soln, pos + 1, ans + s[pos], valid - 1);
            if (pos < s.size() - 1 && s[pos + 1] != ')')
                removeInvalidParentheses(s, soln, pos + 1, ans, valid);
        }
        else
            removeInvalidParentheses(s, soln, pos + 1, ans + s[pos], valid);
    }
    vector<string> removeInvalidParentheses(string s)
    {
        vector<string> soln;
        removeInvalidParentheses(s, soln);
        return soln;
    }
};

int main()
{
    string s;
    cin >> s;
    vector<string> soln = Solution().removeInvalidParentheses(s);
    for (string s : soln)
        cout << s << " ";
}