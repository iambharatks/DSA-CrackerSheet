#include <bits/stdc++.h>

using namespace std;
//39. Row with max 1s
void printMat(vector<vector<int>> mat)
{
    for (vector<int> m : mat)
    {
        for (int i : m)
            cout << i << " ";
        cout << '\n';
    }
}
void rotateby90(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i > j)
                swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / 2; j++)
            swap(matrix[i][j], matrix[i][n - j - 1]);
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
//rotating Cyclicly
//use square matrix
void rotate90Anti(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            int tmp = mat[i][j];
            mat[i][j] = mat[j][n - i - 1];
            mat[j][n - i - 1] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[n - j - 1][i];
            mat[n - j - 1][i] = tmp;
            printMat(mat);
            cout << '\n';
        }
    }
}
void rotate90(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            int tmp = mat[i][j];
            mat[i][j] = mat[n - j - 1][i];
            mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
            mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
            mat[j][n - i - 1] = tmp;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (auto &v : matrix)
    {
        for (int &i : v)
            cin >> i;
    }
    rotate90(matrix);
    cout << "Rotated Matrix\n";
    printMat(matrix);
}