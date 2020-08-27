/*
https://cses.fi/problemset/task/1679
*/

#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > adjacent;
map <int, int> Deg;
int n, m, tmp;
queue <int> q;
vector <int> ans;

void Init ()
{
    scanf ("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i <= n; ++i)
    {
        adjacent.push_back(vector<int>());
    }
    for (int i = 0; i < m; ++i)
    {
        scanf ("%d%d", &u, &v);
        adjacent[u].push_back(v);
        Deg[v]++;
    }
}

void CheckAC ()
{
    for (int i = 1; i <= n; ++i) if (Deg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        int v;
        for (int i = 0; i < adjacent[u].size(); ++i)
        {
            v = adjacent[u][i];
            Deg[v]--;
            if (Deg[v] == 0) q.push(v);
        }
    }
    if (ans.size() < n) printf ("IMPOSSIBLE");
    else for (int i = 0; i < n; ++i)
    {
        printf ("%d ", ans[i]);
    }
}

int main ()
{
    Init();
    CheckAC();
    return 0;
}