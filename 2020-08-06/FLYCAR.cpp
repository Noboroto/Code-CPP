#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "FLYCAR" + (string)".INP";
    const string FileOUT = "FLYCAR" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 6 + 1;
int n, k, h[N];
pair <long long, long long> f[N][N];
long long ans = 1e18 + 7, tmp_equal, tmp_minus;

int main ()
{
    //Init();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            f[N][N] = make_pair (1e9 + 7, 1e9 + 7);
        }
    }
    for (int t = 1; t <= n; ++t)
    {
        if (h[t] < h[1]) continue;
        for (int i = 1; i <= n; ++i)
        {
            if (i == 1) 
            {
                f[i][0].first = h[t];
                f[i][0].second = h[t] - h[1];
            }
            else 
            {
                for (int j = 0; j <= min (k, i - 2); j++)
                {
                    tmp_equal = (f[i - 1][j].first - h[i] > 0) ? f[i - 1][j].second + f[i - 1][j].first - h[i] : 1e18 + 1; 
                    tmp_minus = (j > 0) ? f[i - 1][j - 1].second : 1e18 + 7; 
                    if (tmp_equal <= tmp_minus)
                    {
                        f[i][j] = make_pair (f[i][j - 1].first, tmp_equal);
                    }
                    else
                    {
                        f[i][j] = make_pair (h[i], tmp_minus);
                    }
                }
            }
        }
        for (int i = 1; i <= k; ++i)
        {
            ans = min (f[n][i].second, ans);
        }
    }
    cout << ans;
    return 0;
}