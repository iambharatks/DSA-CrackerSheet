#include <bits/stdc++.h>

using namespace std;

//18. Common elements
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0, cnt = 0;
    unordered_map<int, bool> mp;
    vector<int> soln;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            if (!mp[A[i]])
                soln.push_back(A[i]);
            mp[A[i]] = true;
            ++cnt, ++i, ++j, ++k;
        }
        else if (A[i] < B[j])
            ++i;
        else if (B[j] < C[k])
            ++j;
        else
            ++k;
    }
    return soln;
}

int main()
{
    int n1, n2, n3;
    cin >> n1;
    int A[n1];
    for (int &i : A)
        cin >> i;
    cin >> n2;
    int B[n2];
    for (int &i : B)
        cin >> i;
    cin >> n3;
    int C[n3];
    for (int &i : C)
        cin >> i;
    vector<int> v = commonElements(A, B, C, n1, n2, n3);
    for (int i : v)
        cout << i << " ";
}