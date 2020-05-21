#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    int to;
    long long time;
    Edge (int _to = 0, long long _time = 0)
    {
        to = _to;
        time = _time;
    }
};

const int N = 100 + 1;
const long long oo = 1e18 + 7;
int n, m;
long long f[N];
vector < vector <Edge> > adj;

long long BFS ()
{
    queue <int> q;
    q.push(1);
    while (!q.empty())
    {
        long long u = q.front();
        q.pop();
        if (u == n) break;
        for (int i = 0; i < adj[u].size(); ++i)
        {
            int v = adj[u][i].to;
            long long c = adj[u][i].time;
            f[v] = max (f[v], c + f[u]);
            q.push(v);
        }
    }
    return f[n];
}

int main()
{
    freopen("SUADUONG.INP", "r", stdin);
    freopen("SUADUONG.OUT", "w", stdout);
    cin >> n >> m;
    adj.clear();
    for (int i = 0; i < n; ++i)
    {
        adj.push_back(vector<Edge>());
        f[i + 1] = 0;
    }
    int u, v, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> c;
        adj[u].push_back(Edge(v, c));
    }
    long long ans = BFS ();
    cout << ans;
    return 0;
}
