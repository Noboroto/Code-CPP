/*
https://cses.fi/problemset/task/1668
*/

#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > adjacent;

map <int, int> Team, Trace;
int n, m, tmp;
bool AC = false;

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
        adjacent[v].push_back(u);
    }
}

bool DFS (int const point, int team)
{
    Team[point] = team;
    if (team == 1) team = 2;
    else team = 1;
    for (int i = 0; i < adjacent[point].size(); ++i)
    {
        tmp = adjacent[point][i];
        if (Trace[tmp] != 0 && Trace[tmp] != point && Team[tmp] != team) return false;
        else if (Team[tmp] != 0 && Trace[tmp] != point) continue;
        Trace[tmp] = point;
        if (!DFS (tmp, team)) return false;
    }
    return true;
}

int main ()
{
    Init();
    for (int i = 1; i <= n; ++i) 
    {
        if (Trace[tmp] != 0) continue;
        if (!DFS (i, 1))
        {
            printf ("IMPOSSIBLE");
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", Team[i]);
    return 0;
}