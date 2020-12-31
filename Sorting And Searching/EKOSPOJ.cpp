#include <bits/stdc++.h>

using namespace std;
// 112. EKO - Eko

bool woodCut(int *height, int n, int wood, int curMark)
{
    int woodcut = 0;
    for (int i = 0; i < n; i++)
    {
        int curwood = max(height[i] - curMark, 0);
        if (woodcut + curwood >= wood)
            return true;
        woodcut += curwood;
    }
    return false;
}

int sawbladeHeight(int *height, int n, int wood)
{
    int low = 0, high = 0;
    for (int i = 0; i < n; i++)
        high = (high < height[i]) ? height[i] : high;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (woodCut(height, n, wood, mid))  
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int n, wood;
    cin >> n >> wood;
    int height[n];
    for (int i = 0; i < n; i++)
        cin >> height[i];
    cout << sawbladeHeight(height, n, wood);
}
