#include <bits/stdc++.h>

using namespace std;

//158. First non-repeating character in a stream

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<bool> vis(26, 0);
        char ch;
        while (cin >> ch)
        {
            if (!vis[ch - 'a'])
            {
                cout << ch << " ";
                vis[ch - 'a'] = true;
            }
            else
                cout << -1 << " ";
        }
        cout << endl;
    }
}