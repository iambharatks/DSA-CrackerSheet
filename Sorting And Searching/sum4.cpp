#include <bits/stdc++.h>

using namespace std;

// 97.Find All Four Sum Numbers
//Time := O(n*n*n)
void fourSum(vector<int> &A, int target)
{
    int n = A.size();
    sort(A.begin(), A.end());
    for (int i = 0; i < n - 3; ++i)
    {
        for (int j = i + 1; j < n - 2; ++j)
        {
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                if (A[i] + A[j] + A[k] + A[l] == target)
                {
                    cout << A[i] << " " << A[j] << " " << A[k] << " " << A[l] << " $";
                    k++, l--;
                }
                else if ((A[i] + A[j] + A[k] + A[l] > target))
                    l--;
                else
                    k++;
            }
        }
    }
}
int main()
{
    int n, target;
    cin >> n >> target;
    vector<int> A(n);
    for (int &i : A)
        cin >> i;
    fourSum(A, target);
}