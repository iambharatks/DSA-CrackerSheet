#include <bits/stdc++.h>

using namespace std;
//100.Merge Without Extra Space
void merge(int a1[], int a2[], int n1, int n2)
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
    int n1, n2;
    cin >> n1 >> n2;
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; i++)
        cin >> a1[i];
    for (int i = 0; i < n2; i++)
        cin >> a2[i];
    merge(a1, a2, n1, n2);
    for (int i = 0; i < n1; i++)
        cout << a1[i] << " ";
    for (int i = 0; i < n2; i++)
        cout << a2[i] << " ";
}