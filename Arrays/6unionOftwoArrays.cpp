#include <iostream>

using namespace std;
// 6. Find the Union and Intersection of the two sorted arrays.
const int N = 100001;
int main()
{
    int T;
    cin >> T;
    while (T--)
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
}