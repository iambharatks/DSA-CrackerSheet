#include <iostream>

using namespace std;
//10. Minimum no. of Jumps to reach end of an array
int minJumps(int arr[], int n)
{
    int jumps[n] = {0};
    for (int i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (int j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                jumps[i] = jumps[j] + 1;
                break;
            }
        }
    }
    if (jumps[n - 1] >= INT_MAX)
        return -1;
    return jumps[n - 1];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int arr[n] = {0};
        for (int &i : arr)
            cin >> i;
        cout << minJumps(arr, n) << "\n";
    }
}