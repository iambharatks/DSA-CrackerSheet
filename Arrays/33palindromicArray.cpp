#include <bits/stdc++.h>

using namespace std;

//33. Find minimum number of merge operations to make an array palindrome

void minMerge(vector<int> a)
{
    int n = a.size();
    int i = 0, j = n - 1;
    int ans = 0;
    while (i < j)
    {
        if (a[i] == a[j])
        {
            ++i;
            --j;
        }
        else if (a[i] > a[j])
        {
            j--;
            a[j] += a[j + 1];
            ans++;
        }
        else
        {
            i++;
            a[i] += a[i - 1];
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;
    minMerge(v);
}