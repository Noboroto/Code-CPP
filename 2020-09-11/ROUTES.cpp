#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("ROUTEs.INP", "r", stdin);
    freopen ("ROUTEs.OUT", "w", stdout);
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
        if (x > b.x) return true;
        if (x == b.x && y > b.y) return true;
        return false;
    }
};

const int N = 1e5 + 1;
long long a[N], b[N];
int n, m, k, p;
priority_queue <Point> blocked;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int u, v;
    Init();
    cin >> n >> m >> k >> p;
    for (int i = 0; i < k; ++i)
    {
        cin >> u >> v;
        blocked.push(Point(u, v));
    }
    b[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j) a[j] = b[j];
        for (int j = 1; j <= m; ++j)
        {
            if (i == blocked.top().x && j == blocked.top().y)
            {
                blocked.pop();
                b[j] = 0;
                continue;
            }
            b[j] = (b[j - 1] + a[j]) % p;
        }
    }
    cout << b[m];
    return 0;
}