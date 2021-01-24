#include <bits/stdc++.h>
using namespace std;

class petrolPump
{
public:
    int petrol;
    int distance;
};

int tour(vector<petrolPump> arr)
{
    int start = 0, rear = 1;
    int n = arr.size();
    int curPetrol = arr[start].petrol - arr[start].distance;
    while (start != rear || curPetrol < 0)
    {
        while (curPetrol < 0 && rear != start)
        {
            curPetrol -= arr[start].petrol - arr[start].distance;
            start = (start + 1) % n;
            if (start == 0)
                return -1;
        }
        curPetrol += arr[rear].petrol - arr[rear].distance;
        rear = (rear + 1) % n;
    }
    return start;
}

int main()
{
    int n;
    cin >> n;
    vector<petrolPump> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].petrol;
    for (int i = 0; i < n; i++)
        cin >> p[i].distance;
    cout << tour(p);
}