#include <bits/stdc++.h>

using namespace std;
// 118.ANARC05B(Double Helix)
long long solve(vector<long long> seq1, vector<long long> seq2)
{
    int i = 0, j = 0;
    int n1 = seq1.size(), n2 = seq2.size();
    long long sum1 = 0, sum2 = 0, finalSum = 0;
    while (i < n1 && j < n2)
    {
        if (seq1[i] == seq2[j])
        {
            finalSum += ((sum1 > sum2) ? sum1 : sum2) + seq1[i];
            sum1 = 0, sum2 = 0;
            i++, j++;
        }
        else
        {
            if (seq1[i] < seq2[j])
                sum1 += seq1[i++];
            else
                sum2 += seq2[j++];
        }
    }
    while (i < n1)
        sum1 += seq1[i++];
    while (j < n2)
        sum2 += seq2[j++];
    finalSum += (sum1 > sum2) ? sum1 : sum2;
    return finalSum;
}
int main()
{
    int n1, n2;
    while (true)
    {
        cin >> n1;
        if (n1 == 0)
            break;
        vector<long long> seq1(n1);
        for (long long &i : seq1)
            cin >> i;
        cin >> n2;
        vector<long long> seq2(n2);
        for (long long &i : seq2)
            cin >> i;
        cout << solve(seq1, seq2) << "\n";
    }
}