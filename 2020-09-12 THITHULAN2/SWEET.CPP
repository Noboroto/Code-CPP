#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("SWEET.INP", "r", stdin);
    freopen ("SWEET.OUT", "w", stdout);
}

typedef long long ll;
ll n, l, r, k, du, luot, ans = 0;

int main ()
{
    Init();
    cin >> n >> l >> r >> k;
    if (l <= r)
    {
        r = abs (l - r) + 1;
    }
    else
    {
        r = n - l + r + 1;
    }
    l = 1;
    if (k % n > r)
    {
        du = (k % n) - r;
    }
    else if (k % n == r)
    {
        du = 0;
    }
    else 
    {
        du = n + (k % n) - r;
    }
    luot = (k / n) - (k % n == 0);
    ll tmp = 0;
    while (luot > 0)
    {
        for (int i = 0; i <= (n - r); ++i)
        {
            for (int j = 0; j <= r; ++j)
            {
                tmp = du - i*luot - j*(luot + 1);
                if (tmp == 0) ans = max (ans, (ll)(i + j));
                if (tmp < 0) break;
            }
        }
        luot--;
        du += n;
    }
    cout << ans;
    return 0;
}