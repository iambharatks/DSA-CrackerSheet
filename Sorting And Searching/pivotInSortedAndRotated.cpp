#include <bits/stdc++.h>

using namespace std;
//108. Find pivot element in a sorted and rotated array

int findMin(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (mid < high && nums[mid] > nums[mid + 1])
            return nums[mid + 1];
        if (mid > low && nums[mid] < nums[mid - 1])
            return nums[mid];
        if (nums[low] >= nums[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return nums[0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    cout << findMin(a);
}
