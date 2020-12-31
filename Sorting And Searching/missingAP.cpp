#include <bits/stdc++.h>

using namespace std;
//114. Arithmetic Number
int inSequence(int A, int B, int C)
{
    // code here
    if ((A > 0 && C > 0 && B < 0) || (A < 0 && C < 0 && B > 0) || (A > 0 && C < 0 && B > A) || (A < 0 && C > 0 && B < A))
        return 0;
    if (C == 0)
    {
        return A == B;
    }
    if (abs(B - A) % abs(C) == 0)
        return 1;
    return 0;
}
int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    cout << inSequence(A, B, C);
}