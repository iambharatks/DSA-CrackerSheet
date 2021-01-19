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
        return (celebrity == -1) ? -1 : celebrity + 1;
    }
    
    //optimal Solution Using Stack
    //Time Complexity := O(n)
    //Space Complexity := O(n)
    int celebrityUsingStack(vector<vector<int>> &M, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
            s.push(i);
        int a, b;
        while (s.size() > 1)
        {
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();
            if (M[a][b])
                s.push(b);
            else
                s.push(a);
        }
        if (s.empty())
            return -1;
        int c = s.top();
        s.pop();
        for (int i = 0; i < n; i++)
        {
            if (i != c)
                if (M[c][i] || !M[i][c])
                    return -1;
        }
        return c;
    }

    //Optimnal Solution
    //Time Complexity := O(n)
    //Space Complexity := O(1)
    int celebrity(vector<vector<int>> &M, int n)
    {
        int a = 0, b = n - 1;
        while (a < b)
        {
            if (M[a][b])
                a++;
            else
                b--;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != a)
                if (M[a][i] || !M[i][a])
                    return -1;
        }
        return a;
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
    cout << Solution().celebrity(M, n);
}