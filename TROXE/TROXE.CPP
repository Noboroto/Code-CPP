#include <cstdio>
#include <iostream>

typedef long long ll;
using namespace std;

const int N = 10109999 + 1, M = 10102010;

int main (){
    freopen ("TROXE.INP", "r", stdin);
    freopen ("TROXE.OUT", "w", stdout);
    ll k, x, ans = 0;
    ll a[N];
    for (int i = M; i < N; ++i) a[i] = 0;
    cin >> k;
    for (int i = 0; i < k; ++i){
        cin >> x;
        a[x]++;
    }
    for (ll i = M; i < N; ++i){
        ans = (a[i] != 0) ? ans + 100 + max ((ll)0, a[i] - 5) : ans;
    }
    cout << ans;
    return 0;
}