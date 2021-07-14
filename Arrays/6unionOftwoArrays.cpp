#include <bits/stdc++.h>

using namespace std;
// 6. Find the Union and Intersection of the two sorted arrays.
const int N = 100001;
void solve1()
{
    int n, m;
    int freq[N] = {0};
    cin >> n >> m;
    int A[n], B[m];
    int cnt = 0;
    for (int &i : A)
    {
        cin >> i;
        ++freq[i];
    }
    for (int &i : B)
    {
        cin >> i;
        ++freq[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (freq[i])
            cnt++;
    }
    cout << cnt << "\n";
}
bool binarySearch(vector<int> arr, int key)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}
//Time Complexity := O((m+n)log(min(n,m)))
//Space Complexity := O(min(n,m))
void solve2()
{
    int n, m;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for (int &i : arr1)
        cin >> i;
    for (int &i : arr2)
        cin >> i;
    vector<int> u;
    if (m > n)
    {
        swap(arr1, arr2);
        swap(m, n);
    }
    sort(arr1.begin(), arr1.end());
    u = arr1;
    for (int i = 0; i < n; i++)
    {
        if (!binarySearch(arr1, arr2[i]))
            u.push_back(arr2[i]);
    }
    for (int i : u)
        cout << i << ' ';
}
int main()
{
    //solve1();
    solve2();
}