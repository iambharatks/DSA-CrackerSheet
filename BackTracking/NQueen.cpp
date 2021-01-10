#include <bits/stdc++.h>

using namespace std;
int cnt = 0;
bool isOccupied(int r, int c, int n, bool *diagonal1, bool *diagonal2, bool *col)
{
    return (col[c] || diagonal1[r + c] || diagonal2[c - r + n - 1]);
}

void solutions(int n, int r, bool *diagonal1, bool *diagonal2, bool *col, vector<int> sol)
{
    if (r == n)
    {
        cnt++;
        cout << "[";
        for (int i : sol)
            cout << i << " ";
        cout << "] ";
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (isOccupied(r, c, n, diagonal1, diagonal2, col))
            continue;
        sol.push_back(c + 1);
        col[c] = diagonal1[c + r] = diagonal2[c - r + n - 1] = 1;
        solutions(n, r + 1, diagonal1, diagonal2, col, sol);
        col[c] = diagonal1[c + r] = diagonal2[c - r + n - 1] = 0;
        sol.pop_back();
    }
}

void nQueen(int n)
{
    bool diagonal1[2 * n - 1], diagonal2[2 * n - 1], col[n];
    memset(diagonal1, 0, sizeof(diagonal1));
    memset(diagonal2, 0, sizeof(diagonal2));
    memset(col, 0, n);
    solutions(n, 0, diagonal1, diagonal2, col, {});
    if(cnt == 0)
        cout<<-1<<endl;
    else 
        cout<<endl;
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cnt = 0;
        cin >> n;
        nQueen(n);
    }
}