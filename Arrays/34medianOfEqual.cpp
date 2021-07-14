#include <bits/stdc++.h>

using namespace std;
//O(logn)
// 34. Median of two sorted arrays of equal sizes
int median(int a[], int n)
{
    if (n & 1)
        return a[n / 2];
    return (a[n / 2] + a[n / 2 + 1]) / 2;
}

int getMedian(int a1[], int a2[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return (a1[0] + a2[0]) / 2;
    if (n == 2)
    {
        return (max(a1[0], a2[0]) + min(a1[1], a2[1])) / 2;
    }
    int m1 = median(a1, n);
    int m2 = median(a2, n);
    if (m1 == m2)
        return m1;
    if (m1 < m2)
    {
        if (n & 1)
            return getMedian(a1 + n / 2, a2, n - n / 2);
        return getMedian(a1 + n / 2 - 1, a2, n - n / 2 + 1);
    }
    if (n & 1)
        return getMedian(a2 + n / 2, a1, n - n / 2);
    return getMedian(a2 + n / 2 - 1, a1, n - n / 2 - 1);
}

int main()
{
    int n;
    cin >> n;
    int a1[n], a2[n];
    for (int &i : a1)
        cin >> i;
    for (int &i : a2)
        cin >> i;
    cout << getMedian(a1, a2, n);
}