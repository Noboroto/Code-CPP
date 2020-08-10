#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
int a[N], b[N], n, m, s;

void start (){
    cin >> n >> m >> s;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    sort(b + 1, b + m + 1);
}

int found (int x){
    int l = 1, r = m;
    while (l <= r){
        int g = (l + r) / 2;
        if (b[g] == x) return 1;
        if (b[g] < x) l = g + 1;
        else r = g - 1;
    }
    return 0;
}

void solve (){
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int x = s - a[i];
        ans += found(x);
    }
    cout << ans;
}

int main(){
    //freopen("LINKKIEN.INP", "r", stdin);
    //freopen("LINHKIEN.OUT", "w", stdout);
    start();
    solve();
    return 0;
}
