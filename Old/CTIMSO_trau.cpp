#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main (){
    freopen ("CTIMSO.INP", "r", stdin);
    freopen ("CTIMSO.OUT", "w", stdout);
    ll n, m, k = 0;
    cin >> n >> m;
    ll giaithua = 1, ans = 1;
    for (ll i = 2; i <= n; ++i) giaithua *= i;
    for (ll i = 1; ans <= n; ++i){
        ans *=m;
        if (giaithua % ans == 0) k = max (i, k);
    }
    cout << k;
    return 0;
}