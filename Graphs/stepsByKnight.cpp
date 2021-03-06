#include <bits/stdc++.h>

using namespace std;

class Solution
{

    vector<vector<bool>> visited;
    int move_count;
    bool reached_end;
    queue<int> qr, qc;
    int nodes_in_next_layer;
    int nodes_left_in_layer;

public:
    Solution()
    {
        move_count = 0;
        reached_end = false;
        nodes_in_next_layer = 0;
        nodes_left_in_layer = 0;
    }
    void explore_neighbours(int r, int c, int n)
    {
        int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};
        for (int i = 0; i < 8; i++)
        {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if (rr <= 0 || cc <= 0 || rr > n || cc > n)
                continue;
            if (visited[rr][cc])
                continue;
            qr.push(rr);
            qc.push(cc);
            visited[rr][cc] = true;
            nodes_in_next_layer++;
        }
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        visited.resize(n + 1, vector<bool>(n + 1, 0));
        qr.push(KnightPos[0]);
        qc.push(KnightPos[1]);
        visited[KnightPos[0]][KnightPos[1]] = true;
        nodes_left_in_layer++;
        while (!qr.empty())
        {
            int r = qr.front();
            int c = qc.front();
            qr.pop();
            qc.pop();
            // cout << r << " " << c << " " << move_count << "\n";
            if (r == TargetPos[0] && c == TargetPos[1])
            {
                reached_end = true;
                break;
            }
            explore_neighbours(r, c, n);
            nodes_left_in_layer--;
            if (nodes_left_in_layer == 0)
            {
                swap(nodes_in_next_layer, nodes_left_in_layer);
                move_count++;
            }
        }
        if (reached_end)
            return move_count;
        return -1;
    }
};
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}