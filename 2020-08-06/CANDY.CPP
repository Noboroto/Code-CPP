#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "CANDY" + (string)".INP";
    const string FileOUT = "CANDY" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 500 + 1;
const int C = 1e5 + 1;
int n, tmp;
int a[N], f[N][C];
long long sum = 0;

void Prepare ()
{
    cin >> n;
    tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tmp = max (tmp, a[i]);
        sum += a[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= C; ++j)
        {
            f[i][j] = -1;
        }
    }
    f[0][0] = 0;
}

void DP ()
{
    for (int i = 1; i <= n ; ++i)
    {
        for (int j = 0; j <= sum; ++j)
        {
            f[i][j] = max (f[i][j], f[i - 1][j]);
            if (f[i - 1][j + a[i]] != -1) f[i][j] = max (f[i][j], (f[i - 1][j + a[i]] + a[i]));
            if (f[i - 1][ abs (j - a[i])] != -1)  f[i][j] = max (f[i][j], (f[i - 1][ abs (j - a[i])] + a[i]));
        }
    }
}

int main ()
{
    Init();
    Prepare();
    DP();
    cout << sum - f[n][0] / 2;
    return 0;
}