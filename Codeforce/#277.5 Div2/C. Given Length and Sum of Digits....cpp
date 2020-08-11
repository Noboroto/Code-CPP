#include <bits/stdc++.h>

using namespace std;

const int N = 100 + 1; 
int n, s, fl[N][10], fr[N][10];
int ansleft [N], ansright[N];

void Init ()
{
    cin >> n >> s;
    fl[0][0] = -(1e9+7);
    fr[0][0] = (1e9+7);
    for (int i = 1; i <= 9; ++i)
    {
        fl[0][i] = s;
        fr[0][i] = s;
    }
}

int main ()
{
    Init();
    int t_l, t_r;
    if (n == 1 && s < 10) cout << s << " " << s;
    else if (s > 9*n || s < 1) cout << "-1 -1";
    else 
    {
        for (int i = 1; i <= n; ++i)
        {
            t_l = 9;
            t_r = 0;
            for (int j = 0; j < 10; ++j)
            {
                t_l = (fl[i - 1][t_l] - t_l < fl[i - 1][9 - j] -(9 - j) && fl[i - 1][9 - j] -(9 - j) <= 9*(n - i) && fr[i - 1][9 - j] >= 0) ? 9 - j : t_l;
                t_r = (fr[i - 1][t_r] - t_r > fr[i - 1][j] - j && fr[i - 1][j] - j <= 9*(n - i) && fr[i - 1][j] - j >= 0) ? j : t_r;
            }
            ansleft[i] = t_l;
            ansright[i] = t_r;
            for (int j = 0; j < 10; ++j)
            {
                fl[i][j] = fl[i - 1][t_l] - t_l ;
                fr[i][j] = fr[i - 1][t_r] - t_r ;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            cout << ansleft[i];
        }
        cout << " ";
        for (int i = 1; i <= n; ++i)
        {
            cout << ansright[i];
        }
    }
    return 0;
}