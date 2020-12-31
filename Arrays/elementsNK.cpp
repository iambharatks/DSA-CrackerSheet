#include <iostream>

using namespace std;
//24. Given an array of size n and a number k, find all elements that appear more than n/k times

struct eleCount
{
    int e;
    int c;
};

//Time := O(n*k)
//Space := O(k)
void usingTetris(int arr[], int n, int k)
{
    if (k < 2)
        return;
    struct eleCount temp[k - 1];
    for (int i = 0; i < k - 1; ++i)
        temp[i].c = 0;
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = 0; j < k - 1; ++j)
        {
            if (temp[j].e == arr[i])
            {
                temp[j].c += 1;
                break;
            }
        }
        if (j == k - 1)
        {
            int l;
            for (l = 0; l < k - 1; ++l)
            {
                if (temp[l].c == 0)
                {
                    temp[l].e = arr[i];
                    temp[i].c = 1;
                    break;
                }
            }
            if (l == k - 1)
            {
                for (l = 0; l < k; ++l)
                    temp[l].c -= 1;
            }
        }
    }
    for (int i = 0; i < k - 1; ++i)
    {
        int ac = 0;
        for (int j = 0; j < n; ++j)
        {
            if (arr[j] == temp[i].e)
                ac++;
        }
        if (ac > n / k)
            cout << temp[i].e << " appears " << ac << " times\n";
    }
    cout << endl;
}
//Time := O(n)
//Space := O(n)
void optimal(int arr[], int n, int k)
{
    int mp[100001] = {0};

    for (int i = 0; i < n; ++i)
    {
        mp[arr[i]]++;
    }
    int appearance = n / k, cnt = 0;
    for (int i = 1; i <= 100000; ++i)
    {
        if (mp[i] > appearance)
            cout << i << " appears " << mp[i] << " times\n";
    }
    cout << endl;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    usingTetris(arr, n, k);
    optimal(arr, n, k);
}