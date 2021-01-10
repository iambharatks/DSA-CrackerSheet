#include <bits/stdc++.h>

using namespace std;

void breakWords(unordered_set<string> &dict, string word, int start, set<string> &soln, string ans = "")
{
    if (start == word.size())
    {
        ans = ans + ")";
        soln.insert(ans);
        return;
    }
    if (start > word.size())
        return;
    for (int size = 1; size + start <= word.size(); size++)
    {
        string res = word.substr(start, size);
        if (dict.find(res) == dict.end())
            continue;
        if (!ans.empty())
            res = " " + res;
        else
            res = "(" + res;
        breakWords(dict, word, start + size, soln, ans + res);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_set<string> dict;
        set<string> soln;
        string word;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            dict.insert(s);
        }
        cin >> word;
        breakWords(dict, word, 0, soln);
        for (string s : soln)
            cout << s;
        cout << '\n';
    }
}