#include <bits/stdc++.h>

using namespace std;
//16. Best Time to Buy and Sell Stock
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> stock(n);
        for (int &i : stock)
            cin >> i;
        int max_profit = 0, sell_price = stock[0];

        for (int i = 1; i < n; ++i)
        {
            if (stock[i] >= sell_price)
                max_profit = max(max_profit, stock[i] - sell_price);
            else
                sell_price = stock[i];
        }
        cout << max_profit << "\n";
    }
}