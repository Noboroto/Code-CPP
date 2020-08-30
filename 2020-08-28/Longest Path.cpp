/*
https://atcoder.jp/contests/dp/tasks/dp_g
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int oo = 1e9 + 7;
vector <vector <int> > adj;
int n, m;
int f[N], ans = 0;
bool Visited[N];

void Init ()
{
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        adj.push_back(vector<int>());
    }
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void DFS (int pos)
{
    Visited[pos] = true;
    for (int i = 0; i < adj[pos].size(); ++i)
    {
        if (!Visited[adj[pos][i]]) DFS (adj[pos][i]);
        f[pos] = max (f[pos], f[adj[pos][i]] + 1);
    }
}

int main ()
{
    Init();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (Visited[i]) continue;
        DFS(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        ans = max (ans, f[i]);
    }
    cout << ans;
    return 0;
}