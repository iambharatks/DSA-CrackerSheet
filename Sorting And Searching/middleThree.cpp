#include <bits/stdc++.h>

using namespace std;

//92. Maximum and minimum of an array using minimum number of comparisons

//TimeComplexity : O(n)
//Number of comparisons
//T(n) =T(floor(n/2)) + T(ceil(n/2)) + 2
//T(2) = 1
//T(1) = 0
pair<int, int> getMinMax(vector<int> A, int low, int high)
{
    pair<int, int> minMax;
    if (low == high)
    {
        minMax = {A[low], A[high]};
        return minMax;
    }
    if (high == low + 1)
    {
        if (A[low] < A[high])
            minMax = {A[low], A[high]};
        else
            minMax = {A[high], A[low]};
        return minMax;
    }
    int mid = low + (high - low) / 2;
    pair<int, int> leftMinMax = getMinMax(A, low, mid);
    pair<int, int> rightMinMax = getMinMax(A, mid + 1, high);
    minMax.first = (leftMinMax.first < rightMinMax.first) ? leftMinMax.first : rightMinMax.first;
    minMax.second = (leftMinMax.second > rightMinMax.second) ? leftMinMax.second : rightMinMax.second;
    return minMax;
}
pair<int, int> getMinMax(vector<int> A)
{
    pair<int, int> minMax;
    int n = A.size();
    int i = 2 - (n & 1);
    if (n & 1)
        minMax = {A[0], A[0]};
    else
    {
        if (A[0] > A[1])
            minMax = {A[1], A[0]};
        else
            minMax = {A[0], A[1]};
    }
    while (i < n - 1)
    {
        if (A[i] < A[i + 1])
        {
            minMax.first = (A[i] < minMax.first) ? A[i] : minMax.first;
            minMax.second = (A[i + 1] > minMax.second) ? A[i + 1] : minMax.second;
        }
        else
        {
            minMax.first = (A[i + 1] < minMax.first) ? A[i + 1] : minMax.first;
            minMax.second = (A[i] > minMax.second) ? A[i] : minMax.second;
        }
        i += 2;
    }
    return minMax;
}
int middle(int A, int B, int C)
{
    if ((A - B) * (A - C) < 0)
        return A;
    else if ((B - C) * (B - A) < 0)
        return B;
    else
        return C;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int &i : A)
            cin >> i;
        pair<int, int> minMax = getMinMax(A, 0, n - 1);
        cout << minMax.first << " " << minMax.second << "\n";
    }
}