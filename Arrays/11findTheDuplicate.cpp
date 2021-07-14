#include <iostream>

using namespace std;
//11. find duplicate in an array of N+1 Integers
int findDuplicate(int *arr, int n)
{
    if (n == 2)
        return arr[0];
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);
    fast = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    cout << findDuplicate(arr, n);
}