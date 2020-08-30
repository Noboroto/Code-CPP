#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 +1;
const int oo = 1e9 + 7;
int n, m;
ll factorial[N];

void Init ()
{
    freopen ("RECT.INP", "r", stdin);
    freopen ("RECT.OUT", "w", stdout);
    factorial[0] = 1;
    for (int i = 1; i < N; ++i) factorial[i] = (factorial[i - 1] * i) % oo;
}

ll Pow (ll a, ll n)
{
    if (a < 2) return a;
    if (n == 0) return 1;
    if (n == 1) return a % oo;
    ll t = Pow (a, n / 2) % oo;
    if (n % 2 == 0) return (t * t) % oo;
    else return (((t * t) % oo) * a % oo) % oo;
}

void GetData ()
{
    scanf ("%d%d", &n, &m);
}

ll GetResult ()
{
    ll a = n + m;
    return (factorial[a] * Pow ((factorial[n] * factorial[m]) % oo, oo - 2)) % oo;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    Init();
    int t;
    scanf ("%d", &t);
    while (t > 0)
    {
        t--;
        GetData();
        printf ("%lld\n", GetResult());
    }
    return 0;
}