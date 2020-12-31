#include <bits/stdc++.h>

using namespace std;

//107. Kth smallest number again

#define S second
#define F first

bool compare(pair<long long , pair<long long , long long >> A, pair<long long , pair<long long , long long >> B)
{
    return A.F < B.F;
}
void removeOverlaps(vector<pair<long long , long long >> &r)
{
    vector<pair<long long , long long >> temp;
    temp.push_back(r[0]);
    long long i = 1, n = r.size(), k = 0;
    while (i < n)
    {
        if (r[i].first <= temp[k].second)
            temp[k].second = max(r[i].second, temp[k].second);
        else
            temp.push_back(r[i]), k++;
        i++;
    }
    r = temp;
}
int main()
{
    long long T;
    cin >> T;
    while (T--)
    {
        long long N, Q;
        cin >> N >> Q;
        vector<pair<long long , long long >> r(N);
        for (long long i = 0; i < N; ++i)
            cin >> r[i].first >> r[i].second;
        sort(r.begin(), r.end());
        removeOverlaps(r);
        N = r.size();
        vector<long long > cumulative(N);
        // for (auto i : r)
        //     cout << i.F << " " << i.S << "\n";
        for (long long i = 0; i < N; ++i)
        {
            if (i == 0)
                cumulative[i] = r[i].second - r[i].first + 1;
            else
                cumulative[i] = cumulative[i - 1] + r[i].second - r[i].first + 1;
        }

        while (Q--)
        {
            long long k;
            cin >> k;
            long long pos = lower_bound(cumulative.begin(), cumulative.end(), k) - cumulative.begin();
            if (pos != N)
            {
                long long tK;
                if (pos == 0)
                    tK = r[pos].first + k - 1;
                else
                    tK = r[pos].first + (k - cumulative[pos - 1]) - 1;
                cout << tK << "\n";
            }
            else
                cout << "-1\n";
        }
    }
}