#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "PASSWORD" + (string)".INP";
    const string FileOUT = "PASSWORD" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e3 + 1;
int n, m, x[N], y[N], f[N][N], ans = 0;

int main ()
{
    Init();
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int j = 1; j <= m; ++j) cin >> y[j];
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (x[i] == y[j])
            {
                if (i <= 2 || j <= 2) f[i][j] = 1;
                else f[i][j] = f[i - 2][j - 2] + 1;
            }
            else if (i > 1 && j > 1) f[i][j] = max (f[i - 1][j], f[i][j - 1]);
            ans = max (ans, f[i][j]);
        }
    }
    cout << ans;
    return 0;
}