#include <bits/stdc++.h>

using namespace std;
//51.Count and Say
string nextSequence(int n, string prevSeq)
{
    // cout << prevSeq << "\n";
    if (n == 1)
        return prevSeq;
    string nextSeq = "";
    char prevDigit = prevSeq[0];
    int digitCnt = 0;
    for (int i = 0; i < prevSeq.size(); ++i)
    {
        char digit = prevSeq[i];
        if (digit == prevDigit)
        {
            ++digitCnt;
        }
        else
        {
            nextSeq = nextSeq + char(digitCnt + '0');
            nextSeq = nextSeq + prevDigit;
            prevDigit = digit;
            digitCnt = 1;
        }
        if (i == prevSeq.size() - 1)
        {
            nextSeq = nextSeq + char(digitCnt + '0');
            nextSeq = nextSeq + prevDigit;
        }
    }
    return nextSequence(n - 1, nextSeq);
}
string countAndSayRecursive(int n)
{
    return nextSequence(n, "1");
}
string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string prevSeq = "1";
    for (int j = 2; j <= n; ++j)
    {
        string nextSeq = "";
        char prevDigit = prevSeq[0];
        int digitCnt = 0;
        for (int i = 0; i < prevSeq.size(); ++i)
        {
            char digit = prevSeq[i];
            if (digit == prevDigit)
            {
                ++digitCnt;
            }
            else
            {
                nextSeq = nextSeq + char(digitCnt + '0');
                nextSeq = nextSeq + prevDigit;
                prevDigit = digit;
                digitCnt = 1;
            }
            if (i == prevSeq.size() - 1)
            {
                nextSeq = nextSeq + char(digitCnt + '0');
                nextSeq = nextSeq + prevDigit;
            }
        }
        prevSeq = nextSeq;
    }
    return prevSeq;
}

int main()
{
    int n;
    cin >> n;
    cout << countAndSay(n);
}