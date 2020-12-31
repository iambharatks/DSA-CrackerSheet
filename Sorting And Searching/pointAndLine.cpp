#include <bits/stdc++.h>

using namespace std;
//93. Optimum location of point to minimize total distance
#define sq(x) ((x) * (x))
#define E 1e-6

class point
{
public:
    int x, y;
    point(int x = 0, int y = 0) : x(x), y(y) {}
    double dist(point p)
    {
        return sqrt(sq(p.x - x) + sq(p.y - y));
    }
};
class line
{
public:
    int a, b, c;
    line(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};

double compute(line L, vector<point> P, int x)
{
    int y = -1 * (L.a * x + L.c) / L.b;
    double f = 0;
    for (int i = 0; i < P.size(); i++)
        f += point(x, y).dist(P[i]);
    return f;
}
point optimumPoint(vector<point> P, line L)
{
    double low = -1e5;
    double high = 1e5;
    while ((high - low) > E)
    {
        double x1 = low + (high - low) / 3;
        double x2 = high - (high - low) / 3;
        double f1 = compute(L, P, x1);
        double f2 = compute(L, P, x2);
        if (f1 > f2)
            low = x1;
        else
            high = x2;
    }
    double x = (low + high) / 2;
    double f = compute(L, P, (low + high) / 2);
    cout << "Minimum distance is " << f << "\n";
    double y = -1 * (L.a * x + L.c) / L.b;
    return point(x, y);
}
int main()
{
    int n;
    cin >> n;
    vector<point> P(n);
    for (point &p : P)
        cin >> p.x >> p.y;
    line L;
    cin >> L.a >> L.b >> L.c;
    point p = optimumPoint(P, L);
    cout << "Point is ";
    cout << p.x << " " << p.y << "\n";
}