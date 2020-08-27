#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll N = 1e6 + 1;
const ll oo = 1e9 + 7;
ll factorial[N];

void Init ()
{
    factorial[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        factorial[i] = (factorial[i - 1] * i) % oo;
    }
}

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
    Init();
    ll a, b, t, ans;
    cin >> t;
    while (t > 0)
    {
        t --;
        cin >> a >> b;
        ans = (factorial[a] * Pow ((factorial[b] * factorial[a - b]) % oo, oo - 2)) % oo;
        cout << ans << '\n';
    }
    return 0;
}