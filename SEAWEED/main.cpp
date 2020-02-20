#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;
const int oo = 1e9 + 7, N = 1e5 + 7;
ll f[N], n, k;

void start (){
    cin >> n >> k;
}

ll solve (){
    f[0] = 1;
    f[1] = 2;
    for (ll i = 2; i <= k; ++i){
        f[i] = (f[i] + f[i - 1]) % oo;
        for (ll j = 0; j < i; ++j){
            f[i] += ((f[j] - f[j - 1]) * (i - j)) % oo;
        }
    }
    return f[k];
}

int main(){
    freopen("SEAWEED.INP", "r", stdin);
    freopen("SEAWEED.OUT", "w", stdout);
    start();
    ll ans = (n*solve()) % oo;
    cout << ans;
    return 0;
}
