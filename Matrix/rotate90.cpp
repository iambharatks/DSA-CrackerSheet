#include <bits/stdc++.h>

using namespace std;
//39. Row with max 1s

void rotate90(vector<vector<int>> &matrix, int r, int c)
{
    
}


int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (auto &v : matrix)
    {
        for (int &i : v)
            cin >> i;
    }
    rotate90(matrix, r, c);
}