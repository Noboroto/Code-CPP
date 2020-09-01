#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point 
{
    ll x, y;
    Point (ll _x = 0, ll _y = 0)
    {
        x = _x;
        y = _y;
    }
};

struct Rectangle 
{
    Point A, B, C, D;
    Rectangle (Point a, Point d)
    {
        A = a;
        B = Point (d.x, a.y);
        C = Point (a.x, d.y);
        D = d;
    }
    ll GetSquare ()
    {
        return abs (A.x - D.x) * abs (A.y - D.y);
    }
};

void Init ()
{
    freopen ("RECT2.INP", "r", stdin);
    freopen ("RECT2.OUT", "w", stdout);
}

int main ()
{
    //Init();
    return 0;
}