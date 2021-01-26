#include <bits/stdc++.h>

using namespace std;

//Young Tableau
void youngify(vector<vector<int>> &mat, int i, int j)
{
    int N = mat.size();
    int downVal = (i + 1 < N) ? mat[i + 1][j] : INT_MAX;
    int rightVal = (j + 1 < N) ? mat[i][j + 1] : INT_MAX;
    if (downVal == INT_MAX && rightVal == INT_MAX)
        return;
    if (downVal < rightVal)
    {
        mat[i][j] = downVal;
        mat[i + 1][j] = INT_MAX;
        youngify(mat, i + 1, j);
    }
    else
    {
        mat[i][j] = rightVal;
        mat[i][j + 1] = INT_MAX;
        youngify(mat, i, j + 1);
    }
}

int extractMin(vector<vector<int>> &mat)
{
    int ret = mat[0][0];
    mat[0][0] = INT_MAX;
    youngify(mat, 0, 0);
    return ret;
}

void printSorted(vector<vector<int>> mat)
{
    int N = mat.size();
    for (int i = 0; i < N * N; i++)
        cout << extractMin(mat) << " ";
}
//Time Complexity := O(2*n*n*log(n))
//Space Complexity := O(n*n)
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    // code here
    vector<int> tmp;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            tmp.push_back(Mat[i][j]);
    }
    int x = 0;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Mat[i][j] = tmp[x++];
    return Mat;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto &v : mat)
        for (int &i : v)
            cin >> i;
    vector<vector<int>> sortedMat = sortedMatrix(n, mat);
    for (auto &v : sortedMat)
    {
        for (int &i : v)
            cout << i << " ";
        cout << '\n';
    }
    printSorted(mat);
}