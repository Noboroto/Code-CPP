#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int N = 1e6 + 1;

pair <ll, ll> a[N];
ll n;

int main (){
    freopen ("GAMENUM.INP", "r", stdin);
    freopen ("GAMENUM.OUT", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i){
        ll x;
        cin >> x;
        a[i] = make_pair (abs(x), x);
    }
    sort (a, a + n);
    ll ans = 1e18 + 7;
    for (int i = 0; i < n - 1; i++)
    {
        ans = min (ans, abs (a[i].second + a[i+1].second));
    }
    cout << ans;
    return 0;
}