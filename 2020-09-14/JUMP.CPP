#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("JUMP.INP", "r", stdin);
    freopen ("JUMP.OUT", "w", stdout);
}

typedef long long ll;
int n;
map <int, map <int, int> > Val;

ll GetValue (int x, int y)
{
    if (x < 1 || y < 1) return 0;
    if (Val[x][y] != 0) return Val[x][y];
    int cheo = x + y - 1;
    if (cheo > n)
    {
        if ((n - (cheo - n)) % 2 == 0)
        {
            return GetValue(n, cheo - n) + (y - (cheo - n));
        }
        else
        {
            return GetValue(cheo - n, n) + (x - (cheo - n));
        }
    }
    else
    {
        if (cheo % 2 == 0)
        {
            return GetValue(cheo - 1, 1) + y;
        }
        else
        {
            return GetValue(1, cheo - 1) + (cheo - y + 1);
        }
    }
    return 0;
}

int main ()
{
    auto a = clock();
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    string s;
    ll sum = 1;
    int x = 1, y = 1;
    Init();
    int m;
    cin >> n >> m;
    Val[1][1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        GetValue(1, i);
        GetValue(i, 1);
    }

    for (int i = 1; i <= n; ++i)
    {
        GetValue(n, i);
        GetValue(i, n);
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << GetValue(j, i) << "  ";
            if (GetValue(j, i) < 10) cout << " ";
        }
        cout << "\n";
    }

    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'D')
        {
            y++;
        }
        if (s[i] == 'U')
        {
            y--;
        }
        if (s[i] == 'R')
        {
            x++;
        }
        if (s[i] == 'L')
        {
            x--;
        }
        sum += GetValue(x, y);
    }
    cout << sum;
    return 0;
}