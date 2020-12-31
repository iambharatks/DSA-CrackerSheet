#include <bits/stdc++.h>

using namespace std;
// 116. Painter's Partition Problem

bool isPossible(vector<long long> board, long long painters, long long maxUnits)
{
    long long paintersReq = 1;
    long long painted = 0;
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        if (board[i] > maxUnits)
            return false;
        else if (painted + board[i] > maxUnits)
        {
            paintersReq++;
            painted = board[i];
        }
        else
        {
            painted += board[i];
        }
        if (paintersReq > painters)
            return false;
    }
    return true;
}

long long timeTaken(vector<long long> board, long long painters)
{
    long long n = board.size();
    long long low = 0, high = 0;
    for (long long i : board)
        high += i;
    long long ans = INT_MAX;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (isPossible(board, painters, mid))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    long long painters, time, n;
    cin >> painters >> time >> n;
    vector<long long> board(n);
    for (long long &i : board)
        cin >> i;
    cout << timeTaken(board, painters) * time << "\n";
}