#include <bits/stdc++.h>

using namespace std;
//19. Rearrange array in alternating positive & negative items with O(1) extra space 
void rightRotate(int start, int end, vector<int> &arr)
{
    int temp = arr[end];
    for (int i = end; i > start; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

void rearrange(vector<int> &arr)
{
    int n = arr.size();
    int outOfPlace = -1;
    for (int i = 0; i < n; ++i)
    {
        if (outOfPlace >= 0)
        {
            if ((arr[outOfPlace] >= 0 && arr[i] < 0) || (arr[outOfPlace] < 0 && arr[i] >= 0))
            {
                rightRotate(outOfPlace, i, arr);
                if (i - outOfPlace >= 2)
                    outOfPlace += 2;
                else
                    outOfPlace = -1;
            }
        }
        if (outOfPlace == -1)
        {
            if ((arr[i] >= 0 && ((i + 1) & 1)) || ((arr[i] < 0 && ((i + 1) & 1) == 0)))
                outOfPlace = i;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    rearrange(a);
    for (int i : a)
        cout << i << " ";
    cout << endl;
}