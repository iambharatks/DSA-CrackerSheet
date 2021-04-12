#include <bits/stdc++.h>

using namespace std;

class recursion
{
    int maxim(int a, int b, int c) { return max(max(a, b), c); }

public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        if (n <= 0 || m <= 0)
            return 0;
        int left = (m > 0) ? maxGold(n, m - 1, M) : 0;
        int leftUp = (m > 0 && n > 0) ? maxGold(n - 1, m - 1, M) : 0;
        int leftDown = (m > 0 && n < M.size()) ? maxGold(n + 1, m - 1, M) : 0;
        return M[n - 1][m - 1] + maxim(left, leftDown, leftUp);
    }
};
class memoization
{
    vector<vector<int>> table;
    int maxim(int a, int b, int c) { return max(max(a, b), c); }

public:
    int maxGoldUtil(int n, int m, vector<vector<int>> M)
    {
        if (n < 0 || m < 0)
            return 0;
        int left = (m > 0) ? maxGold(n, m - 1, M) : 0;
        int leftUp = (m > 0 && n > 0) ? maxGold(n - 1, m - 1, M) : 0;
        int leftDown = (m > 0 && n < M.size()) ? maxGold(n + 1, m - 1, M) : 0;
        if (table[n][m] != -1)
            return table[n][m];
        return table[n][m] = M[n - 1][m - 1] + maxim(left, leftDown, leftUp);
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        table.resize(n + 1, vector<int>(m + 1, -1));
        return maxGoldUtil(n, m, M);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m, 0));
    for (vector<int> &v : M)
        for (int &i : v)
            cin >> i;
    cout << recursion().maxGold(n, m, M);
}