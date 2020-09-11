#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("nazi.INP", "r", stdin);
    freopen ("nazi.OUT", "w", stdout);
}

struct Point 
{
    int x, y, o;
    Point (int _x = 0, int _y = 0, int _o = 0)
    {
        x = _x;
        y = _y;
        o = _o;
    }
};

const int N = 1e2 + 1;
const int Dx[4] = {0, 1, 0, -1};
const int Dy[4] = {1, 0,-1, 0};
int n, m, t, i;
int Checked[N][N];
queue <Point> q;

void Prepare ()
{
    int u, v;
    cin >> n >> m >> t;
    for (i = 0; i < t; ++i) 
    {
        cin >> u >> v;
        q.push (Point (u, v, 1));
        Checked[u][v] = false;
    }
}

void BFS ()
{
    int ans = 0;
    Point u, v;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        ans = max (ans, u.o);
        for (i = 0; i < 4; ++i)
        {
            v = Point (u.x + Dx[i], u.y + Dy[i], u.o + 1);
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > m || Checked[v.x][v.y]) continue;
            Checked[v.x][v.y] = true;
            q.push(v);
        }
    }
    cout << ans;
}

int main ()
{
    Init();
    Prepare();
    BFS();
    return 0;
}