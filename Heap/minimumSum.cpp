#include <bits/stdc++.h>

using namespace std;
// Minimum sum
class Solution
{
public:
    void percolateDown(int *arr, int n, int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int min;
        if (left < n && arr[left] > arr[i])
            min = left;
        else
            min = i;
        if (right < n && arr[right] > arr[min])
            min = right;
        if (min != i)
        {
            swap(arr[i], arr[min]);
            percolateDown(arr, n, min);
        }
    }
    void heapify(int *arr, int n)
    {
        for (int i = (n - 1) / 2; i >= 0; i--)
            percolateDown(arr, n, i);
    }
    int popMax(int *arr, int &n)
    {
        if (n == 0)
            return -1;
        n--;
        int min = arr[0];
        arr[0] = arr[n];
        percolateDown(arr, n, 0);
        return min;
    }
    string solve(int arr[], int n)
    {
        string s = "";
        heapify(arr, n);
        int carry = 0;
        while (n)
        {
            int n1 = popMax(arr, n) + carry;
            if (n > 0)
                n1 += popMax(arr, n);
            if (n1 >= 10)
            {
                n1 -= 10;
                carry = 1;
            }
            else
                carry = 0;
            s = char(n1 + '0') + s;
        }
        if (carry)
            s = '1' + s;
        int i = 0;
        while (s[i] == '0')
            i++;
        s = s.substr(i);
        return s;
    }
};
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int &i : arr)
        cin >> i;
    cout << Solution().solve(arr, n);
}