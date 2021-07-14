#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    // cout << endl;
}
//12. Merge 2 sorted arrays without using Extra space.
//O(n*m)
void brute(int *a1, int n1, int *a2, int n2)
{
    int i = 0, j = 0;
    while (i != n1)
    {
        if (a1[i] > a2[j])
        {
            swap(a1[i], a2[j]);
        }
        else
        {
            ++i;
            continue;
        }
        for (int k = j + 1; k < n2; k++)
        {
            if (a2[k] <= a2[k - 1])
                swap(a2[k], a2[k - 1]);
            else
                break;
        }
        // print(a1, n1);
        // print(a2, n2);
        j = 0;
    }
}
// O(n *logn)
void gapMethod(int *a1, int n1, int *a2, int n2)
{
    int gap = n1 + n2, i, j;
    for (gap = (gap <= 1) ? 0 : (gap / 2) + (gap & 1); gap > 0; gap = (gap <= 1) ? 0 : (gap / 2) + (gap & 1))
    {
        for (i = 0; i + gap < n1; ++i)
            if (a1[i] > a1[i + gap])
                swap(a1[i], a1[i + gap]);
        for (j = gap > n1 ? gap - n1 : 0; i < n1 && j < n2; ++i, ++j)
            if (a1[i] > a2[j])
                swap(a1[i], a2[j]);
        if (j < n2)
        {
            for (j = 0; j + gap < n2; ++j)
                if (a2[j] > a2[j + gap])
                    swap(a2[j], a2[j + gap]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    for (int &i : a1)
        cin >> i;
    for (int &i : a2)
        cin >> i;
    // merge(a1, a2, n, m);
    gapMethod(a1, n, a2, m);
    print(a1, n);
    print(a2, m);
}
