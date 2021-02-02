// { Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX 5
vector<string> findPath(int m[MAX][MAX], int n);
// Position this line where user code will be pasted.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m[MAX][MAX];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        vector<string> result = findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

// Rat in a Maze Problem - I
vector<vector<bool>> visited;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void dfs(int r, int c, int mat[MAX][MAX], int &n, string s, vector<string> &ans)
{
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(s);
        return;
    }
    visited[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int rr = r + dr[i];
        int cc = c + dc[i];
        if (rr < 0 || cc < 0 || rr >= n || cc >= n)
            continue;
        if (mat[rr][cc] == 0)
            continue;
        if (!visited[rr][cc])
            dfs(rr, cc, mat, n, s + dir[i], ans);
    }
    visited[r][c] = false;
}
vector<string> findPath(int mat[MAX][MAX], int n)
{
    string s = "";
    if (mat[0][0] == 0)
        return {};
    vector<string> ans;
    visited.resize(n, vector<bool>(n, 0));
    dfs(0, 0, mat, n, s, ans);
    sort(ans.begin(), ans.end());
    return ans;
}