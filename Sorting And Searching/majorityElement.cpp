#include <bits/stdc++.h>

using namespace std;
//94. Majority Element

int countInRange(vector<int> &a, int low, int right, int key)
{
    int cnt = 0;
    for (int i = low; i <= right; i++)
    {
        if (a[i] == key)
            ++cnt;
    }
    return cnt;
}

int majElement(vector<int> &a, int low, int high)
{
    int n = a.size();
    if (low == high)
        return a[low];
    int mid = low + (high - low) / 2;
    int left = majElement(a, low, mid);
    int right = majElement(a, mid + 1, high);
    if (left == right)
        return left;
    int leftCount = countInRange(a, low, mid, left);
    int rightCount = countInRange(a, mid + 1, high, right);
    return (leftCount > rightCount) ? left : right;
}

int majElement(vector<int> a)
{
    int m = majElement(a, 0, a.size() - 1);
    int cnt = 0;
    for (int i : a)
        if (i == m)
            cnt++;
    if (cnt > a.size() / 2)
        return m;
    return -1;
}
//MO's Voting Algo
int majorityElement(vector<int> &a)
{
    int n = a.size();
    int maj = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == maj)
            cnt++;
        else
            cnt--;
        if (cnt == 0)
        {
            maj = a[i];
            cnt = 1;
        }
    }
    cnt = 0;
    for (int i : a)
    {
        if (i == maj)
            ++cnt;
    }
    if (cnt > n / 2)
        return maj;
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    cout << majorityElement(a);
}