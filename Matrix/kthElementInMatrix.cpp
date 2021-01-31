#include <bits/stdc++.h>

using namespace std;
#define MAX 1000
//Time Complexity := O(klogn)
//Space Complaxity := O(n)
struct comparator
{
    bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.first > b.first;
    }
};
int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comparator> pq;
    for (int i = 0; i < n; i++)
        pq.push({mat[i][0], {i, 1}});
    pair<int, pair<int, int>> tmp;
    pair<int, pair<int, int>> ans;

    for (int i = 0; i < k; i++)
    {
        tmp = pq.top();
        pq.pop();
        ans = tmp;
        // cout<<tmp.first<<" ";
        if (tmp.second.second < n)
            tmp.first = mat[tmp.second.first][tmp.second.second];
        else
            tmp.first = INT_MAX;
        tmp.second.second += 1;
        pq.push(tmp);
    }
    return ans.first;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int mat[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    cout << kthSmallest(mat, n, k);
}