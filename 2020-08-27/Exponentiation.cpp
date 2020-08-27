/*
https://cses.fi/problemset/task/1095
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const oo = 1e9 + 7;

ll Pow (ll a, ll n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    ll t = Pow (a, n / 2) % oo;
    if (n % 2 == 0) return (t * t) % oo;
    else return ((t * t) % oo) * a % oo; 
}

int main ()
{
    int t, a, n;
    scanf ("%d", &t);
    while (t > 0)
    {
        t--;
        scanf ("%d%d", &a, &n);
        printf ("%lld\n", Pow (a, n));
    }
    return 0;
}