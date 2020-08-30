/*
https://atcoder.jp/contests/dp/tasks/dp_o
*/
#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;
bool AC[22][22], Visited[22];
int n, i, j, x;
long long ans = 0;

void Init ()
{
    scanf ("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            scanf ("%d", &x);
            if (x == 1) AC [i][j] = true;
            else AC[i][j] = false;
        }
    }
}

void Check (int pos)
{
    if (pos > n)
    {
        ans++;
        ans %= oo;
    }
    for (i = 1; i <= n; ++i)
    {
        if (!AC[pos][i]) continue;
        if (Visited[i]) continue;
        Visited[i] = true;
        Check (pos + 1);
        Visited[i] = false;
    }
}

int main ()
{
    Init();
    Check (1);
    printf ("%d", ans);
    return 0;
}