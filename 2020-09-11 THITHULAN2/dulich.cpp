#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen("DULICH.INP", "r", stdin);
    freopen("DULICH.OUT", "w", stdout);
}

typedef long long ll;

const int N = 10 + 1;
int n, p, c[N];
vector <vector <int> > adj (N);
ll ans = 0;
bool Visited[N];

void GetData()
{
    int u, v;
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        Visited[i] = false;
    }
    for (int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void DFS (int pos, int Counting, ll Sum)
{
    if (Counting == p)
    {
        ans = max (ans, Sum);
    }
    Visited[pos] = true;
    for (int i = 0; i < (int)adj[pos].size(); ++i)
    {
        if (Visited[adj[pos][i]] || adj[pos][i] <= pos) continue;
        DFS (adj[pos][i], Counting + 1, Sum + c[adj[pos][i]]);
    }
    Visited[pos] = false;
}

int main()
{
    Init();
    GetData();
    for (int i = 1; i <= n; ++i)
    {
        DFS (i,1, c[i]);
    }
    cout << ans;
    return 0;
}
