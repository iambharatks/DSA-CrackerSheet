#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//103. Sort by Set Bit Count 

bool compare(int a, int b)
{
    int cnt1 = 0, cnt2 = 0;
    while (a)
    {
        a = a & (a - 1);
        cnt1++;
    }
    while (b)
    {
        b = b & (b - 1);
        cnt2++;
    }
    return cnt1 >= cnt2;
}

void merge(int arr[], int l, int m, int r, bool (&cmp)(int a, int b))
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    i = j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (cmp(L[i], R[j]))
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r, compare);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}