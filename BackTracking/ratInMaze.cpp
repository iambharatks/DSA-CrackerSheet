#include <bits/stdc++.h>

using namespace std;
#define MAX 5
// Rat in a Maze Problem - I
bool isBlocked(int m[MAX][MAX], int x, int y, int n)
{
    if ((x >= n) || (y >= n) || (x < 0) || (y < 0))
        return true;
    return (m[x][y] == 0);
}
bool isEnd(int m[MAX][MAX], int x, int y, int n)
{
    return ((x == n - 1) && (y == n - 1));
}
void rateInMaze(int m[MAX][MAX], int x, int y, int n, vector<string> &paths, string path = "")
{
    if (isBlocked(m, x, y, n))
        return;
    if (isEnd(m, x, y, n))
    {
        paths.push_back(path);
        return;
    }
    m[x][y] = 0;
    //down
    rateInMaze(m, x + 1, y, n, paths, path + 'D');
    //up
    rateInMaze(m, x - 1, y, n, paths, path + 'U');
    //left
    rateInMaze(m, x, y - 1, n, paths, path + 'L');
    //right
    rateInMaze(m, x, y + 1, n, paths, path + 'R');
    m[x][y] = 1;
}
vector<string> findPath(int m[MAX][MAX], int n)
{
    vector<string> paths;
    rateInMaze(m, 0, 0, n, paths);
    return paths;
}

int main()
{
    int n;
    cin >> n;
    int maze[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> maze[i][j];
    vector<string> paths = findPath(maze, n);
    for (string s : paths)
        cout << s << " ";
}