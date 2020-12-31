#include <bits/stdc++.h>

using namespace std;

//25. Maximum profit by buying and selling a share at most twice

void sellStock(vector<int> price)
{
    int n = price.size();
    vector<int> profit(n, 0);
    int buy = price[0], sell = price[n - 1];
    int maximumProfit = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (price[i + 1] >= sell)
        {
            sell = price[i + 1];
            continue;
        }
        if (sell - price[i + 1] > maximumProfit)
            maximumProfit = sell - price[i + 1];
        profit[i] += maximumProfit;
    }
    maximumProfit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i - 1] <= buy)
        {
            buy = price[i - 1];
            continue;
        }
        if (price[i - 1] - buy > maximumProfit)
            maximumProfit = price[i - 1] - buy;
        profit[i] += maximumProfit;
    }
    maximumProfit = 0;
    for (int i : profit)
    {
        cout << i << " ";
        maximumProfit = (maximumProfit < i) ? i : maximumProfit;
    }
    cout << "\n";
    cout << "Maximum Profit in atmost 2 transaction is: " << maximumProfit << "\n";
}

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    vector<int> profit(n, 0);
    for (int &i : price)
        cin >> i;
    sellStock(price);
}