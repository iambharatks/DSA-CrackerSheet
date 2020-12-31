#include <bits/stdc++.h>

using namespace std;
//91.Count Squares

//constraint n >= 1
int sqrt(int n)
{
    int L = 1, R = n;
    int ans = 0;
    while (L <= R)
    {
        int x = (L + R) / 2;
        if (x * x == n)
            return x;
        if (x * x < n)
        {
            ans = x;
            L = x + 1;
        }
        else
            R = x - 1;
    }
    return ans;
}
int countingSquares(int n)
{
    return floor(sqrt(n - 1));
}
int main()
{
    int n;
    cin >> n;
    cout << sqrt(n - 1);
}