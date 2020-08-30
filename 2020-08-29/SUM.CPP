#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 +1;
const int oo = 1e9 + 7;
int n, m;
ll factorial[N];

void Init ()
{
    freopen ("SUM.INP", "r", stdin);
    freopen ("SUM.OUT", "w", stdout);
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

ll GetResult (ll a, ll b)
{
    return (factorial[a] * Pow ((factorial[b] * factorial[a - b]) % oo, oo - 2)) % oo;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    Init();
    int t, s, n;
    scanf ("%d", &t);
    while (t > 0)
    {
        t--;
        scanf ("%d%d", &n, &s);
        if (n > s) printf ("0\n");
        else 
        {
            printf ("%lld\n", GetResult (s - 1, n - 1));
        }
    }
    return 0;
}