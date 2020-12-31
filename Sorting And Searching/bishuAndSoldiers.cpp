#include <bits/stdc++.h>

using namespace std;

//105. Bishu And Soldiers

int upperBound(vector<int> a, int target)
{
    int n = a.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == target)
        {
            if (mid < high && a[mid + 1] == target)
                low++;
            else
                return mid + 1;
        }
        else if (a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + (high - low) / 2;
}

void solve(int maxPower, vector<int> &soldier)
{
    int pos = upperBound(soldier, maxPower);
    if (pos == -1)
    {
        cout << 0 << " " << 0 << "\n";
        return;
    }
    int sum = 0;
    for (int i = 0; i < pos; i++)
        sum += soldier[i];
    cout << pos << " " << sum << "\n";
}
int main()
{
    int n;
    cin >> n;
    vector<int> soldier(n, 0);
    for (int &i : soldier)
        cin >> i;
    sort(soldier.begin(), soldier.end());
    int q;
    cin >> q;
    while (q--)
    {
        int power;
        cin >> power;
        solve(power, soldier);
    }
}