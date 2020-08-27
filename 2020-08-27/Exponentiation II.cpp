/*
https://cses.fi/problemset/task/1712
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const oo = 1e9 + 7;

ll Pow (ll a, ll n, const ll &oo)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    ll t = Pow (a, n / 2, oo) % oo;
    if (n % 2 == 0) return (t * t) % oo;
    else return (((t * t) % oo) * a % oo) % oo; 
}

int main ()
{
    int t, a, b, c;
    ll tmp;
    scanf ("%d", &t);
    while (t > 0)
    {
        t--;
        scanf ("%d%d%d", &a, &b, &c);
        tmp = Pow (b, c, oo - 1) % oo;
        printf ("%lld\n", Pow (a, tmp, oo));
    }
    return 0;
}