#include <bits/stdc++.h>

using namespace std;
//39. Row with max 1s

void rotate90(vector<vector<int>> &matrix, int r, int c)
{
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (i > j)
                swap(matrix[i][j], matrix[j][i]);
    // for (int i = 0; i < r; i++)
    // {
    //     for (int j = 0; j < c / 2; j++)
    //         swap(matrix[i][j], matrix[i][c - j - 1]);
    // }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}
void rotateby90Anti(vector<vector<int>> &matrix, int n)
{
    // code here
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i > j)
                swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < n / 2; i++)
        swap(matrix[i], matrix[n - i - 1]);
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
    rotateby90Anti(matrix, r);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}