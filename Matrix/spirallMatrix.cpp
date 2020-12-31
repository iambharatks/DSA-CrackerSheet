#include <bits/stdc++.h>

using namespace std;

//36.Traverse matrix spirally
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
            cin >> matrix[i][j];
    }

    int start_row = 0, end_row = r - 1, start_col = 0, end_col = c - 1;
    int move = 0;
    int i = start_row, j = start_col;
    while (start_row <= end_row && start_col <= end_col)
    {
        switch (move)
        {
        case 0:
            for (j = start_col; j <= end_col; ++j)
                cout << matrix[i][j] << " ";
            ++move;
            start_row++;
            j = end_col;
            break;
        case 1:
            for (i = start_row; i <= end_row; ++i)
                cout << matrix[i][j] << " ";
            ++move;
            i = end_row;
            end_col--;
            break;
        case 2:
            for (j = end_col; j >= start_col; --j)
                cout << matrix[i][j] << " ";
            ++move;
            j = start_col;
            end_row--;
            break;
        case 3:
            for (i = end_row; i >= start_row; --i)
                cout << matrix[i][j] << " ";
            move = 0;
            i = start_row;
            start_col++;
            break;
        default:
            cout << "error\n";
            break;
        }
    }
}