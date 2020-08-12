#include <bits/stdc++.h>

using namespace std;

const int N = 1 + 100; //1e4;
int n, k, f[N][3], up = 0;
int ans [N], h[N], down = 0;

void Init ()
{
    const string FileINP = "KMULT" + (string)".INP";
    const string FileOUT = "KMULT" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

void Prepare ()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> h[i];
        h[i] %= k;
        up += h[i];
        down += h[i];
    }
    f[0][0] = (1e9+7);
}

int main ()
{
    //Init();
    Prepare();
    int tmp;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i][0] )
        ans[i] = tmp;
        for (int j = 0; j < 10; ++j)
        {
            f[i][j] = f[i - 1][tmp] - tmp;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i];
    }
    return 0;
}