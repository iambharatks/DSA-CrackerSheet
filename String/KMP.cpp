#include <bits/stdc++.h>

using namespace std;

//63.KMP
bool stringMatching(string text, string pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> resetTable(m, 0);
    int i = 0, j = -1;
    while (i < m)
    {
        while (j >= 0 && pattern[i] != pattern[j])
            j = resetTable[j];
        i++, j++;
        resetTable[i] = j;
    }
    for (int i = 0; i < m; ++i)
        cout << resetTable[i] << " ";
    cout << endl;
    return true;
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    stringMatching(text, pattern);
}