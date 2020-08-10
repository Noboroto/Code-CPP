#include <cstdio>
#include <iostream>

using namespace std;

typedef unsigned long long ll;
ll u, v, t;

void start (){
    cin >> u >> v;
}

ll solve (){
    ll ans = 0;
    ll tmp = u;
    ll x1 = 0, s1 = 0, x2 = 1e9 + 7, s2 = 0;
    while (tmp > 0){
        ll as = tmp % 10;
        x1 = max (x1, as);
        tmp /= 10;
        s1++;
    }
    tmp = v;
    while (tmp > 0){
        ll as = tmp % 10;
        if (as != 0) x2 = min (x2, as);
        tmp /= 10;
        s2++;
    }
    tmp = 0;
    while (tmp < v){
        tmp = tmp*10 + x2;
    }
    if (tmp > v) x2--;
    if (x2 < 1) {
        s2--;
        x2 = 9;
    }
    if (s1 == s2) ans = x2 - x1 + 1;
    else ans = x2 + (10 - x1) + 9*(s2 - s1 - 1);
    return ans;
}

int main (){
    freopen("BORING.INP", "r", stdin);
    freopen("BORING.OUT", "w", stdout);
    start();
    cout << solve();
    return 0;
}
