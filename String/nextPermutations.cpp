#include <bits/stdc++.h>

using namespace std;
//59.nextPermutation in string

void reverse(string &s, int start, int end)
{
    while (start < end)
        swap(s[start++], s[end--]);
}
void nextPermutaion(string &s)
{
    int largest = -1, smallest = -1;
    int n = s.size();
    for (int i = n - 1; i > 0; --i)
    {
        if (s[i] > s[i - 1])
        {
            smallest = i - 1;
            break;
        }
    }
    for (int i = n - 1; i > 0 && smallest != -1; --i)
    {
        if (s[i] > s[smallest])
        {
            largest = i;
            break;
        }
    }
    if (smallest != -1)
        swap(s[largest], s[smallest]);
    reverse(s, smallest + 1, n - 1);
}

int main()
{
    string s;
    cin >> s;
    nextPermutaion(s);
    // swap(s[0], s[1]);
    cout << s << " ";
}