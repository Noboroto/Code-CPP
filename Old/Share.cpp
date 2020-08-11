#include <iostream>
#include <cstdio>

typedef long long ll;
using namespace std;

ll UCLN (ll x, ll y){
    while (y != 0){
        ll r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    freopen("SHARE.INP", "r", stdin);
    freopen("SHARE.OUT", "w", stdout);
    ll n, m;
    cin >> m >> n;
    ll ans = n - UCLN(n, m);
    cout << ans;
    return 0;
}
