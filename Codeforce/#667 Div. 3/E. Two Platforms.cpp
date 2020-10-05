#include <bits/stdc++.h>

using namespace std;
void abc(int u)
{
    cout<<u;
}
void abc(int u, int v)
{
    
}
struct Point 
{
    int x, y;
    Point (int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    bool operator < (const Point &b) const
    {
        if (x < b.x) return true;
        
        if (x == b.y && y < b.y) return true;
        return false;
    }
};

const int N = 2e5 + 1;
Point a[N];
int n, k;

void Init ()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].x;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].y;
    }
    sort (a, a + n);
}

void Solve ()
{
    
}

int main ()
{
    Init();
    
    return 0;
}