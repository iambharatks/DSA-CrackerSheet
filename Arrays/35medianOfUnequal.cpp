#include <bits/stdc++.h>

using namespace std;
//O(logn)
// 35. Median of two sorted arrays of unequal sizes
int max(int a, int b) { return a > b ? a : b; }
int max(int a, int b, int c) { return (a > b) ? (a > c ? a : c) : ((b > c) ? b : c); }
int max(int a, int b, int c, int d) { return max(a, max(a, b, c)); }
int min(int a, int b) { return a < b ? a : b; }
int min(int a, int b, int c) { return (a < b) ? (a < c ? a : c) : ((b < c) ? b : c); }
int min(int a, int b, int c, int d) { return min(a, min(a, b, c)); }
double median(int arr[], int n)
{
    if (n == 0)
        return -1;
    if (n & 1)
        return arr[n / 2];
    return (arr[n / 2] + arr[n / 2 - 1]) / 2.0;
}
double median(int a, int b) { return (a + b) / 2.0; }
double median(int a, int b, int c) { return a + b + c - min(a, b, c) - max(a, b, c); }
double median(int a, int b, int c, int d) { return (a + b + c + d - min(a, b, c, d) - max(a, b, c, d)) / 2.0; }

//by default n <= m
double getMedian(int a1[], int a2[], int n, int m)
{
    if (n == 0)
        return median(a2, m);
    if (n == 1)
    {
        if (m == 1)
            return median(a1[0], a2[0]);
        if (m & 1)
            return median(a1[0], a2[m / 2 - 1], a2[m / 2], a2[m / 2 + 1]);
        return median(a1[0], a2[m / 2], a2[m / 2 - 1]);
    }
    if (n == 2)
    {
        if (m == 2)
            return median(a1[0], a1[1], a2[0], a2[1]);
        if (m & 1)
            return median(a2[m / 2], max(a1[0], a2[m / 2 - 1]), min(a1[1], a2[m / 2 + 1]));
        return median(a2[m / 2], a2[m / 2 - 1], max(a1[0], a2[m / 2 - 2], min(a1[1], a2[m / 2 + 1])));
    }
    int ind1 = (n - 1) / 2, ind2 = (m - 1) / 2;
    if (a1[ind1] <= a2[ind2])
        return getMedian(a1 + ind1, a2, n / 2 + 1, m - ind1);
    return getMedian(a1, a2 + ind1, n / 2 + 1, m - ind1);
}
int findMedian(int arr[], int n, int brr[], int m)
{
    int merged[n + m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (arr[i] <= brr[j])
            merged[k++] = arr[i++];
        else
            merged[k++] = brr[j++];
    }
    while (i < n)
    {
        merged[k++] = arr[i++];
    }
    while (j < m)
    {
        merged[k++] = brr[j++];
    }
    return ((m + n) & 1) ? (merged[(m + n) / 2]) : (merged[(m + n) / 2] + merged[(m + n) / 2 - 1]) / 2;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1[n], a2[m];
        for (int &i : a1)
            cin >> i;
        for (int &i : a2)
            cin >> i;
        int med = ((n <= m) ? getMedian(a1, a2, n, m) : getMedian(a2, a1, m, n));
        cout << med << "\n";
    }
}