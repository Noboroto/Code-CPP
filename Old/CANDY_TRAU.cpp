#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e6;
ll a[N], n, m, ans = 1e18 + 7;

void start (){
    cin >> m >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void solve (ll i, ll s, ll c){
    if (i > n){
        ans = min (ans, c);
        return;
    }
    for (ll j = 0; j <= a[i]; ++j){
        ll r = s - j;
        if (r < 0){
            solve(i + 1, s, a[i]*a[i] + c);
            continue;
        }
        r = a[i] - j;
        ll f = r*r + c;
        solve(i + 1, s - j, f);
    }
}

int main(){
    freopen("CANDY.INP", "r", stdin);
    freopen("CANDY.OUT", "w", stdout);
    start();
    solve(1, m, 0);
    cout << ans;
    return 0;
}
