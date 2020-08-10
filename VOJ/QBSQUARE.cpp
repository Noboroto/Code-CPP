#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 1;
int n, m;

struct Point
{
    int Height, Width, Value, PreSquare;
    int GetMaxSquare ()
    {
        return min (Height, min (Width, PreSquare)) ;
    }
    Point Check_Point (Point const &h, Point const &w, Point p)
    {
        return Point 
        (
            Value,
            (Value == p.Value) * (p.GetMaxSquare() + 1),
            (Value == h.Value) * h.Height + 1,
            (Value == w.Value) * w.Width  + 1 
        );
    }
    Point (int _v = 0, int _p = 0, int _h = 0,int _w = 0)
    {
        Height = _h;
        Width = _w;
        PreSquare = _p;
        Value =_v;
    }
};

Point f[N][N];

void Init ()
{
    const string FileINP = "QBSQUARE" + (string)".INP";
    const string FileOUT = "QBSQUARE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> f[i][j].Value;
            if (i == 0 && j == 0)
            {
                f[i][j] = Point(f[i][j].Value, 1, 1, 1);
            }
            else if (i == 0)
            {
                f[i][j] = f[i][j].Check_Point(Point(f[i][j].Value),f[i][j - 1],Point(f[i][j].Value));
            }
            else if (j == 0)
            {
                f[i][j] = f[i][j].Check_Point(f[i - 1][j],Point(f[i][j].Value),Point(f[i][j].Value));
            }            
        }
    }
}

int main ()
{
    Init();
    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            f[i][j] = f[i][j].Check_Point(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]);
            ans = max (ans, f[i][j].GetMaxSquare());
        }
    }
    cout << ans;
    return 0;
}