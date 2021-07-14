#include <bits/stdc++.h>

using namespace std;
//26. Array Subset of another array

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a1(n), a2(m);
        int mp[100001] = {0};
        for (int &i : a1)
        {
            cin >> i;
            mp[i]++;
        }
        bool isSubset = true;
        for (int &i : a2)
        {
            cin >> i;
            if (!mp[i])
                isSubset = false;
        }
        if (isSubset)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}