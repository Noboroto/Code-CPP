#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3*1e5 + 7;
long long a[N], s[N], f[N], n;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
}

void solve (){
    long long ans = INT_MIN;
    for (int i = 2; i <= n; ++i){
        f[i] = min (f[i - 2], s[i]);
        if (i >= 4) {
            ans = max (ans, s[i] - f[i - 4]);
        }
    }
    cout << ans;
}

int main(){
    freopen("BEAUTY.INP", "r", stdin);
    freopen("BEAUTY.OUT", "w", stdout);
    start();
    solve();
    return 0;
}
