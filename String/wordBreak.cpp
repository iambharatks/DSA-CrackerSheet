#include <bits/stdc++.h>

using namespace std;

//61.Word Break Problem
//TODO:=
//Recursive
void wordBreak(vector<string> dict, string text, int idx, int &cnt)
{
    if (idx == text.length())
    {
        cnt++;
        return;
    }
    for (string word : dict)
    {
        string ros = text.substr(idx, word.size());
        if (ros == word)
            wordBreak(dict, text, idx + word.size(), cnt);
    }
}

bool inDict(string s) {}

void dynamicApproach(vector<string> dict, string text)
{
    int n = text.size();
    vector<bool> dp(n, false);
    dp[0] = true;
}
int main()
{
    int n, cnt = 0;
    string text;
    cin >> text;
    cin >> n;
    vector<string> dict(n);
    for (string &s : dict)
        cin >> s;
    wordBreak(dict, text, 0, cnt);
    cout << cnt << " ";
}