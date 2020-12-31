#include <bits/stdc++.h>

using namespace std;
//104.Minimum Swaps to Sort

int minSwaps(int arr[], int N)
{
    pair<int, int> pos[N];
    bool vis[N];
    memset(vis, 0, N);
    for (int i = 0; i < N; i++)
    {
        pos[i] = {arr[i], i};
    }
    sort(pos, pos + N);
    int min_swaps = 0;
    for (int i = 0; i < N; i++)
    {
        if (vis[i] || arr[i] == pos[i].first)
        {
            vis[i] = true;
            continue;
        }
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = true;
            j = pos[j].second;
            cycle_size++;
        }
        if (cycle_size > 0)
            min_swaps += cycle_size - 1;
    }
    return min_swaps;
}

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int &i : A)
        cin >> i;
    cout << minSwaps(A, n);
}
