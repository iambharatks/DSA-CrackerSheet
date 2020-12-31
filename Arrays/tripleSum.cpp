#include <bits/stdc++.h>

using namespace std;
//27. Find triplet sum
// Time := O(n*n*n)
void bruteForce(vector<int> v, int x)
{
    int n = v.size();
    sort(v.begin(), v.end());
    int i, j, k;
    i = 0, j = 1, k = 2;
    bool ans = false;
    for (i = 0; i < n - 2; ++i)
    {
        if (v[i] > x)
            break;
        for (j = i + 1; j < n - 1; ++j)
        {
            if (v[i] + v[j] > x)
                break;
            for (k = j + 1; k < n; ++k)
            {
                if (v[i] + v[j] + v[k] == x)
                {
                    ans = true;
                    cout << v[i] << " " << v[j] << " " << v[k] << "\n";
                    break;
                }
                if (v[i] + v[j] + v[k] > x)
                    break;
            }
        }
    }
    cout << ans << "\n";
}
// Time := O(n*n)
void twoPointer(vector<int> v, int x)
{
    sort(v.begin(), v.end());
    int n = v.size();
    int i, j, k;
    i = 0, j = 1, k = 2;
    bool ans = false;
    for (i = 0; i < n - 2; ++i)
    {
        if (v[i] > x)
            break;
        j = i + 1, k = n - 1;
        int target = x - v[i];
        while (j < k)
        {
            if (v[j] + v[k] == target)
            {
                cout << v[i] << " " << v[j] << " " << v[k] << "\n";
                cout << 1 << "\n";
                return;
            }
            if (v[j] + v[k] > target)
                k--;
            else
                j++;
        }
    }
    cout << 0 << "\n";
}
//Can apply hashing too.
//Time := O(n*n)
//Space := O(n)

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        // bruteForce(v, x);
        // twoPointer(v, x);
    }
}