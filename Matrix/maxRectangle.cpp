#include <bits/stdc++.h>

using namespace std;
#define MAX 1000

int maxAreaRow(int arr[], int n)
{
    stack<int> h;
    int i = 0;
    int maxArea = 0;
    while (i < n)
    {
        if (h.empty() || arr[h.top()] <= arr[i])
            h.push(i++);
        else
        {
            int tp = h.top();
            h.pop();
            int areaForTp = arr[tp] * ((h.empty()) ? i : i - h.top() - 1);
            maxArea = (maxArea < areaForTp) ? areaForTp : maxArea;
        }
    }
    while (!h.empty())
    {
        int tp = h.top();
        h.pop();
        int areaForTp = arr[tp] * ((h.empty()) ? i : i - h.top() - 1);
        maxArea = (maxArea < areaForTp) ? areaForTp : maxArea;
    }
    return maxArea;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    int maxAreaRec = 0, curArea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != 0 && M[i][j])
                M[i][j] += M[i - 1][j];
            cout << M[i][j] << " ";
        }
        curArea = maxAreaRow(M[i], m);
        cout << " == " << curArea << '\n';
        maxAreaRec = (maxAreaRec < curArea) ? curArea : maxAreaRec;
    }
    return maxAreaRec;
}

int main()
{
    int r, c;
    cin >> r >> c;
    int matrix[MAX][MAX];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    }
    cout << maxArea(matrix, r, c);
}