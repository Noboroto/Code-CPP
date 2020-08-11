#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;
typedef long long lli;
typedef long double ld;

ll a, b, k, x, c;

ll multi(ll x, ll y)
{
    x %= b; y %= b;
    ll q = (ld)x * y / b;
    lli r = lli(x * y - q * b) % lli(b);
    if (r < 0) r += b;
    return r;
}

ll pow(ll a, ll n) {
    if (n == 0) return 1 % b;
    else if (n == 1) return a % b;
    else {
        ll s = pow(a, n/2) % b;
        s = multi(s, s)% b;
        if (s % 2 != 0) s = multi(s, a) % b;
        return s;
    }
}

int main() {
    freopen("DIGIT.INP","r", stdin);
    freopen("DIGIT.OUT","w", stdout);
    cin >> a >> b >> k;
    ll t = pow (10, k - 1);
    t = ((a % b) * (t % b)) % b;
    ll kq = 0, q = 0;
    for (int i = 1; i <= 10; ++i){
        q += t;
        kq += q / b;
        q = q % b;
    }
    cout << kq;
    return 0;
}
