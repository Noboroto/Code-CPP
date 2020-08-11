#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "FLYCAR" + (string)".INP";
    const string FileOUT = "FLYCAR" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 400 + 1;
int n, k;
long long f[N][N],h[N];
long long tmp = -1e18 + 7, max_height;

int main ()
{
    Init();
    cin >> n >> k;   
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
        tmp = max (tmp, (long long)h[i]);
        h[i] += h[i - 1];
        f[i][0] = i*tmp - h[i];
    }
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j <= min (k, i - 1); ++j)
        {
            max_height = h[i] - h[i - 1];
            f[i][j] = 1e18 + 7;
            for (int t = i - 1; t >= 0; --t)
            {
                tmp = f[t][j - 1] + (i - t) * max_height - (h[i] - h[t]);
                f[i][j] = min (tmp, f[i][j]);
                max_height = max (max_height, h[t] - h[t - 1]);
            }
        }
    }
    cout << f[n][k];
    return 0;
}