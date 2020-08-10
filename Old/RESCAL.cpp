#include <iostream>
#include <cstdio>

typedef long long ll;

using namespace std;

ll GCD(ll a, ll b)
{
    return (b == 0) ? a: GCD(b, a % b);
}

int main()
{
    freopen("RESCAL.INP", "r", stdin);
    freopen("RESCAL.OUT", "w",stdout);
    ll n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        cin >> x;
        ll tmp = GCD (k, x);
        k /= tmp;
    }
    cout << k;
    return 0;
}
