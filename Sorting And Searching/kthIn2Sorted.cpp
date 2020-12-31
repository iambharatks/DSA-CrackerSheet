#include <bits/stdc++.h>

using namespace std;
// 109.K-th element of two sorted Arrays

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, M, target;
        cin >> N >> M >> target;
        vector<int> A(N), B(M);
        for (int &i : A)
            cin >> i;
        for (int &i : B)
            cin >> i;
        int i = 0, j = 0, k = 0;
        int ans;
        while (i < N && j < M && k != target)
        {
            if (A[i] < B[j])
            {
                ans = A[i];
                i++, k++;
            }
            else
            {
                ans = B[j];
                j++, k++;
            }
        }
        while (i < N && k != target)
        {
            ans = A[i];
            i++, k++;
        }
        while (j < M && k != target)
        {
            ans = B[j];
            j++, k++;
        }
        cout << ans << "\n";
    }
}