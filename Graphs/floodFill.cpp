#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void dfs(int sr, int sc, int oldColor, int newColor, vector<vector<int>> &image, vector<vector<bool>> &visited)
    {
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        visited[sr][sc] = true;
        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i++)
        {
            int r = sr + dr[i];
            int c = sc + dc[i];
            if (r < 0 || c < 0 || r >= image.size() || c >= image[0].size())
                continue;
            if (image[r][c] != oldColor)
                continue;
            if (!visited[r][c])
                dfs(r, c, oldColor, newColor, image, visited);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), 0));
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
        dfs(sr, sc, oldColor, newColor, image, visited);
        return image;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m, 0));
    for (auto &v : image)
        for (int &i : v)
            cin >> i;
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    Solution().floodFill(image, sr, sc, newColor);
    for (auto &v : image)
    {
        for (int &i : v)
            cout << i << " ";
        cout << endl;
    }
}