/*
https://cses.fi/problemset/task/1668
*/

#include <bits/stdc++.h>

using namespace std;

vector < vector <int> > adjacent;

map <int, int> Team;
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
    }
}

int Counting = 0;

void DFS (int const point, int team)
{
    Team[point] = team;
    if (team == 1) team = 2;
    else team = 1;
    Counting++;
    if (Counting == n)
    {

        return;
    }
    for (int i = 0; i < adjacent[point].size(); ++i)
    {
        tmp = adjacent[point][i];
        if (Team[tmp] != 0 && Team[tmp] != team)
        {
            AC = true;
            return;
        }
        else if (Team[tmp] != 0) continue;
        DFS (tmp, team);
        if (AC) return;
    }
}

int main ()
{
    Init();
    for (int i = 1; i <= n; ++i) printf ("%d ", Team[i]);
    return 0;
}