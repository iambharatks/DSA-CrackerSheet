#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

//21. Factorial of a large number

int multiply(int x, int *res, int res_size)
{
    int carry = 0;
    for (int i = 0; i < res_size; ++i)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res[res_size] = carry % 10;
        carry /= 10;
        ++res_size;
    }
    return res_size;
}
void factorial(int n)
{
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    int k = 0;
    for (int i = 2; i <= n; ++i)
    {
        res_size = multiply(i, res, res_size);
    }
    for (int i = res_size - 1; i >= 0; --i)
        cout << res[i];
    cout << "\n";
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        factorial(n);
    }
}