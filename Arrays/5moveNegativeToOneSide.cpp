#include <iostream>

using namespace std;

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
//5.Move all the negative elements to one side of the array 

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, l = 0;
    while (i < n)
    {
        switch (arr[i] < 0)
        {
        case true:
            swap(arr[i++], arr[l++]);
            break;
        case false:
            i++;
            break;
        }
    }
    print(arr, n);
    return 0;
}