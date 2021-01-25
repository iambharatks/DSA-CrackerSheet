#include <bits/stdc++.h>

using namespace std;

string FirstNonRepeating(string A)
{
    int a[26] = {0};
    queue<char> q;
    string s = "";
    for (char c : A)
    {
        a[c - 'a']++;
        if (a[c - 'a'] == 1)
            q.push(c);
        while (!q.empty())
        {
            if (a[q.front() - 'a'] == 1)
            {
                s += q.front();
                break;
            }
            else
                q.pop();
        }
        if (q.empty())
            s += '#';
    }
    return s;
}

int main()
{
    string A;
    cin >> A;
    cout << FirstNonRepeating(A);
}