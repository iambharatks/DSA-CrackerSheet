#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    //Time Complexity := O(n*n)
    //Space Complexity := O(n)
    int graphSolution(vector<vector<int>> M)
    {
        int n = M.size();
        int celebrity = -1;
        vector<int> followers(n, 0), following(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (M[i][j])
                    followers[j]++, following[i]++;
        int maxFollowers = 0;
        for (int i = 0; i < n; i++)
        {
            if (!following[i] && followers[i] > maxFollowers)
                celebrity = i, maxFollowers = followers[i];
        }
        // +1 for 1-based indexing
        return celebrity + 1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (auto &v : M)
        for (auto &i : v)
            cin >> i;
    cout << Solution().graphSolution(M);
}