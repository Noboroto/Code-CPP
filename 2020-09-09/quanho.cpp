#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("quanho.INP", "r", stdin);
    freopen ("quanho.OUT", "w", stdout);
}

struct Edge
{
    int v;
    long long c;
    Edge(int _v = 0, long long _c = 0)
    {
        v = _v;
        c = _c;
    }
};


struct Point 
{
    int pos;
    long long cake, dis;
    Point (int _pos = 0, long long _cake = 0, long long _dis = 0)
    {
        pos = _pos;
        cake = _cake;
        dis = _dis;
    }

    bool operator < (const Point &b) const
    {
        if (dis > b.dis) return true;
        else if (dis == b.dis && cake < b.cake) return true;
        return false;
    }
};

const int N = 1e5 + 1;
long long Dis[N];
priority_queue <Point> Heap;
vector <pair <long long, long long> > CakeQ;
vector < vector<Edge> > adj;
int n, m, Cake[N];

void Prepare ()
{
    int u, v, c;
    scanf ("%lld", &n);
    adj.assign(n + 1, vector<Edge>());
    for (int i = 1; i <= n; ++i) 
    {
        Dis[i] = (long long)1e18 + 7;
        scanf ("%d", &Cake[i]);
    }
    scanf ("%d", &m);
    for (int i = 0;i < m; ++i)
    {
        scanf ("%d%d%d", &u, &v, &c);
        if (u == 1)
        {
            Dis[v] = min (Dis[v], (long long)c);
        }
        if (v == 1)
        {
            Dis[u] = min (Dis[u], (long long)c);
        }
        adj[u].push_back(Edge(v, c));
        adj[v].push_back(Edge(u, c));
    }
    Dis[1] = -1;
    for (int i = 0; i < adj[1].size(); ++i)
    {
        Heap.push(Point (adj[1][i].v, Cake[adj[1][i].v] + Cake[1], Dis[adj[1][i].v]));
    }
}

void Solve ()
{
    Point u;
    Edge v;
    long long c, ans = 0;
    while (!Heap.empty())
    {
        u = Heap.top();
        Heap.pop();
        if (u.pos == n) 
        {
            if (u.dis == Dis[n]) ans = max (ans, u.cake);
            continue;
        }
        for (int i = 0; i < adj[u.pos].size(); ++i)
        {
            v = adj[u.pos][i];
            c = u.dis + v.c;
            if (Dis[v.v] < c) continue;
            Dis[v.v] = c;
            Heap.push(Point(v.v, u.cake + Cake[v.v], Dis[v.v]));
        }
    }
    sort (CakeQ.begin(), CakeQ.end());
    if (Dis[n] == (long long)1e18 + 7) cout << "impossible";
    else cout << Dis[n] << " " << ans;
}

int main ()
{
    Init();
    Prepare();
    Solve();
    return 0;
}