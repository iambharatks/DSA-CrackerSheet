#include <bits/stdc++.h>

using namespace std;

class Job
{
public:
    int id, dead, profit;
};
class DisjointSet
{
public:
    int *parent;
    DisjointSet(int n) : parent(new int[n]{0}) {}
    int find(int s)
    {
        if (s == parent[s])
            return s;
    }
};
//Method 1
//Time : O(n*n)
bool compare(Job a, Job b)
{
    if (a.profit != b.profit)
        return a.profit > b.profit;
    if (a.dead != b.dead)
        return a.dead < b.dead;
    return a.id < b.id;
}
pair<int, int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    int maxProfit = 0, cnt = 0;
    int result[n];
    bool slot[n];
    memset(slot, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                cnt++;
                result[j] = i;
                maxProfit += arr[i].profit;
                slot[j] = true;
                break;
            }
        }
    }
    return {cnt, maxProfit};
}

//Method 2
//Time := O(n)

int main()
{
    int n;
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].id >> arr[i].dead >> arr[i].profit;
    pair<int, int> res = JobScheduling(arr, n);
    cout << res.first << " " << res.second << "\n";
}