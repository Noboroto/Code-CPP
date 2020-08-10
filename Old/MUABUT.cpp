#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

const int N = 1e5 + 7;
int a[N], b[N], n, m;

int found (int x){
    int l = 1, r = m;
    while (l <= r){
        int g = (l + r) / 2;
        if (b[g] == x) return g;
        else if (b[g] < x) l = g + 1;
        else r = g - 1;
    }
    return 0;
}

void start (){
    cin >> n >> m;
    int x = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        x = max(x, a[i]);
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    sort(b + 1, b + m + 1);
    int ans = found(x);
    cout << x << ' ' << ans;
}

int main(){
    //freopen("MUABUT.INP", "r", stdin);
   // freopen("MUABUT.OUT", "w", stdout);
    start();
    return 0;
}
