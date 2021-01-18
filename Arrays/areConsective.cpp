#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    //Time Complextity := O(n)
    //This method not always works for negative numbers
    bool areConsecutives(long long arr[], int n)
    {
        long long max = *max_element(arr, arr + n);
        long long min = *min_element(arr, arr + n);
        if (max - min + 1 == n)
        {
            for (int i = 0; i < n; i++)
            {
                int j;
                if (arr[i] < 0)
                    j = -arr[i] - min;
                else
                    j = arr[i] - min;
                if (arr[j] > 0)
                    arr[j] = -arr[j];
                else
                    return false;
            }
            return true;
        }
        return false;
    }
};
class Solution
{
public:
    //Time Complextity := O(n)
    //Space Complexity := O(n)
    bool areConsecutives(long long arr[], int n)
    {
        long long max = *max_element(arr, arr + n);
        long long min = *min_element(arr, arr + n);
        if (max - min + 1 == n)
        {
            bool *visited = new bool[n]{0};
            for (int i = 0; i < n; i++)
            {
                if (visited[arr[i] - min])
                    return false;
                visited[arr[i] - min] = true;
            }
            return true;
        }
        return false;
    }
};
