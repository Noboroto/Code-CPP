#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const ll N = 1e5 + 7;
ll a[N], b[N], n, k;

void start (){
    cin >> n >> k;
    for (ll i = 1; i <= n; ++i){
        cin >> a[i] >> b[i];
    }
}

ll found (ll id){
    ll f = 0;
    for (ll i = 1; i <= n; ++i){
        if (a[i] > id) continue;
        if (b[i] == 0) return k + 2;
        f += ((id - a[i]) / b[i]) + 1;
    }
    return f;
}

ll solve (){
    ll l = 0;
    ll r = 1e18 + 1e9, g, ans = 0;
    while (l <= r){
        g = (l + r) / 2;
        ll c = found(g);
        if (c <= k) l = g + 1;
        if (c > k) {
            ans = g;
            r = g - 1;
        }
    }
    return ans;
}

int main(){
    freopen("ATTACK.INP", "r", stdin);
    freopen("ATTACK.OUT", "w", stdout);
    start();
    cout << solve() << endl;
    return 0;
}
