#include <bits/stdc++.h>

using namespace std;
//31.Three Way partitioning

void dnfSort(int a, int b, vector<int> &arr)
{
    int n = arr.size();
    int mid = 0, l = 0, r = n - 1;
    while (mid <= r)
    {
        if (arr[mid] < a)
            swap(arr[l++], arr[mid++]);
        else if (arr[mid] >= a && arr[mid] <= b)
            mid++;
        else
            swap(arr[mid], arr[r--]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &i : A)
        cin >> i;
    int a, b;
    cin >> a >> b;
    dnfSort(a, b, A);
    for (int i : A)
        cout << i << " ";
    cout << endl;
}