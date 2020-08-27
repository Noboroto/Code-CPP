/*
https://cses.fi/problemset/task/1756
*/

#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > ans;
vector < vector <int> > adjacent;
map <int, bool> Visited;
int n, m, tmp;

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
        printf ("%d %d\n", min (u, v), max (u, v));
        adjacent[u].push_back(v);
        adjacent[v].push_back(u);
    }
}

void DFS (int pos)
{
    Visited[pos] = true;
    for (int i = 0; i < adjacent[pos].size(); ++i)
    {
        tmp = adjacent[pos][i];
        if (Visited[i]) continue;
        else 
        {
            ans.push_back(make_pair(pos, tmp));
            DFS(tmp);
        }
    }
}

int main ()
{
    Init();
    /*
    DFS(1);
    for (int i = 0; i < ans.size(); ++i)
    {
        printf ("%d %d\n", ans[i].first, ans[i].second);
    }*/
    return 0;
}