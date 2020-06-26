#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "ANT" + (string)".INP";
    const string FileOUT = "ANT" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int oo = 1e9 + 7;
const int Dx [3] = {1, 0, 1};
const int Dy [3] = {0, 1, 1};
int n, m;
long long ans = 0;

void DFS (int x, int y)
{
    if (x == n && y == m)
    {
        ans++;
        ans %= oo;
    }
    if (x > n || y > m) return;
    for (int i = 0; i < 3; ++i)
    {
        DFS (x + Dx[i], y + Dy[i]);
    }
}

int main ()
{
    Init();
    scanf ("%d %d", &n, &m);
    DFS (0, 0);
    printf ("%lld", ans);
    return 0;
}