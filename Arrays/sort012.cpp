#include <iostream>

using namespace std;
//4.Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sort(int *arr, int n)
{
    int l = 0, r = n - 1, m = 0;
    int temp[n] = {0};
    while (m <= r)
    {
        switch (arr[m])
        {
        case 0:
            swap(arr[l++], arr[m++]);
            break;
        case 1:
            m++;
            break;
        case 2:
            swap(arr[m], arr[r--]);
            break;
        }
    }
    arr = temp;
    free(temp);
}
int main()
{
    int n;
    cin >> n;
    int arr[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, n);
    print(arr, n);
}