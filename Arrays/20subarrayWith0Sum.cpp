#include <bits/stdc++.h>

using namespace std;
//20. Subarray with 0 sum
//Time := O(n)
//Space := O(n)
bool subArrayExists(vector<int> arr)
{
    unordered_map<int, bool> mp;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum == 0 || mp[sum])
            return true;
        mp[sum] = true;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;
    if (subArrayExists(arr))
        cout << "Yes\n";
    else
        cout << "No\n";
}