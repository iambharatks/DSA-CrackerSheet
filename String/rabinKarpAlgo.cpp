#include <bits/stdc++.h>

using namespace std;
#define d 256
//62.Rabin Karp Algo

void search(string text, string pattern, int q)
{
    int M = pattern.size();
    int N = text.size();
    int i, j, p = 0, t = 0, h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == M)
                cout << "Found at " << i << endl;
        }

        if (i < N - M)
        {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string pattern, text;
    getline(cin, text);
    getline(cin, pattern);
    search(text, pattern, 11);
    return 0;
}