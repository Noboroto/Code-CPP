#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "OMEGA" + (string)".INP";
    const string FileOUT = "OMEGA" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 450 + 1;
const long long oo = 1e18 + 1;

int n, m, Head[N], u, v, i, c, k;
long long MinPath[N][N];

void GetData ()
{
    int u, v, c;
    scanf ("%d%d", &n, &m);
    for ( u = 1; u <= n; ++u)
    {
        for ( v = 1; v <= n; ++v)
        {
            MinPath[u][v] = oo;
        }
    }
    for ( i = 1; i <= m; ++i)
    {
        scanf ("%d%d%d", &u, &v, &c);
        MinPath[u][v] = min (MinPath[u][v], (long long)c);
        MinPath[v][u] = min (MinPath[v][u], (long long)c);
    }
}

void Floyd ()
{
    for ( k = 1; k <= n; ++k)
    {
        for ( u = 1; u <=n; ++u)
        {
            for ( v = 1; v <= n; ++v)
            {
                MinPath[u][v] = min (MinPath[u][v], MinPath[u][k] + MinPath[k][v]);
            }
        }
    }
}

void PrintResult ()
{
    long long ans = oo, Counter = 1, sum = 0;
    for ( u = 1; u <= n; ++u)
    {
        sum = 0;
        for ( v = 1; v <=n;++v)
        {
            if (u == v) continue;
            if (MinPath[u][v] == oo) 
            {
                cout << 0;
                return;
            }
            sum += MinPath[u][v];
        }
        if (sum < ans)
        {
            ans = sum;
            Counter = 1;
        }
        else if (sum == ans) Counter++;
    }
    cout << ans << ' ' << Counter;
}

int main ()
{
    Init();
    GetData();
    Floyd();
    PrintResult();
    return 0;
}