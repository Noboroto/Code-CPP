#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LCStrace" + (string)".INP";
    const string FileOUT = "LCStrace" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e3 + 1;
int n, m, x[N], y[N], f[N][N];
pair <int, int> trace[N][N], tmp;
vector <int> anstmp;
pair <int, pair <int, int> > ans;

int main ()
{
    Init();
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    cin >> m;
    for (int j = 1; j <= m; ++j) cin >> y[j];
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (x[i] == y[j])
            {
                if (i <= 1 || j <= 1) f[i][j] = 1;
                else f[i][j] = f[i - 1][j - 1] + 1;
                trace[i][j] = make_pair(i - 1, j - 1);
            }
            else if (i > 1 && j > 1) 
                if (f[i - 1][j] > f[i][j - 1])
                {
                    f[i][j] = f[i - 1][j];
                    trace[i][j] = make_pair(i - 1, j);
                }
                else
                {
                    f[i][j] = f[i][j - 1];
                    trace[i][j] = make_pair(i, j - 1);
                }
            if (ans.first < f[i][j])
            {
                ans.first = f[i][j];
                ans.second = make_pair(i, j);
            }
        }
    }
    cout << ans.first << '\n';
    tmp = ans.second;
    while (tmp.first != 0 && tmp.second != 0)
    {
        if (x[tmp.first] == y[tmp.second]) anstmp.push_back(x[tmp.first]);
        tmp = trace[tmp.first][tmp.second];
    }
    for (int i = anstmp.size() - 1; i >= 0; --i) cout << anstmp[i] << " ";
    return 0;
}