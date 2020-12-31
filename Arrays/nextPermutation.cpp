#include <bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int> &a)
{
    int n = a.size();
    int smallest = -1, largest = -1;
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] > a[i - 1])
        {
            smallest = i - 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0 && smallest != -1; i--)
    {
        if (a[i] > a[smallest])
        {
            largest = i;
            break;
        }
    }
    if (smallest != -1)
        swap(a[smallest], a[largest]);
    reverse(a.begin() + smallest + 1, a.end());
}
void print(vector<int> a)
{
    for (int i : a)
        cout << i << " ";
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    nextPermutation(a);
    print(a);
}