#include <bits/stdc++.h>

using namespace std;
//94. Repeating And Missing
pair<int, int> sorting(vector<int> a)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int prev = 0;
    int missing = 0, repeating;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == prev)
        {
            repeating = prev;
            break;
        }
        prev = a[i];
    }
    prev = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == prev + 2)
        {
            missing = prev + 1;
            break;
        }
        prev = a[i];
    }
    if (missing == 0)
        missing = n;
    return {repeating, missing};
}
//Issue with big integers
pair<int, int> math(vector<int> a)
{
    int n = a.size();
    int i = 1;
    int X = 0, Y = 0;
    for (int ni : a)
    {
        X += (i - ni);
        Y += (i * i - ni * ni);
        i++;
    }
    int repeating, missing;
    Y /= X;
    missing = (Y + X) / 2;
    repeating = missing - X;
    return {repeating, missing};
}
//works best
// O(n)
pair<int, int> xOR(vector<int> a)
{
    int n = a.size();
    int x_y = 0;
    for (int i = 0; i < n; i++)
        x_y ^= ((i + 1) ^ a[i]);
    int num = x_y & (x_y - 1);
    num ^= x_y;
    int repeating = 0, missing = 0;
    for (int i = 0; i < n; i++)
    {
        if (num & a[i])
            missing ^= a[i];
        else
            repeating ^= a[i];
        if (num & (i + 1))
            missing ^= (i + 1);
        else
            repeating ^= (i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (missing == a[i])
        {
            swap(missing, repeating);
            break;
        }
    }
    return {repeating, missing};
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    pair<int, int> p = xOR(a);
    cout << p.first << " " << p.second << "\n";
}