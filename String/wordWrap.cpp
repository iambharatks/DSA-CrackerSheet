#include <bits/stdc++.h>

using namespace std;
//57.Word Wrap
//TODO
void wordWrap(vector<int> v, int limit)
{
    int n = v.size();
    int cnt = 0, i = 0;
    int current = 0;
    while (i < n)
    {
        if (i != n - 1 && current + v[i] + 1 <= limit)
        {
            current += v[i] + 1;
            cout << i + 1 << " ";
        }
        else if (i == n - 1 && current + v[i] <= limit)
        {
            if (i == n - 1)
            {
                cout << i + 1 << " ";
            }
        }
        else
        {
            i -= 1;
            cout << i + 1 << " ";
            current = 0;
        }
        ++i;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, limit;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        cin >> limit;
        wordWrap(v, limit);
        cout << endl;
    }
}
