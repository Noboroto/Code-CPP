#include <iostream>
#include <cstdio>
#include <algorithm>

typedef long long ll;
using namespace std;

struct ob {
    int a, b;
    ob (int _a = 0, int _b = 0){
        a = _a;
        b = _b;
    }
    bool operator < (ob tmp){
        return b < tmp.b;
    }
};

const ll N = 2e5 + 7;
int n, f[N], cl [N];
ob o[N];
long long s[N];
long long ans = 1e18 + 7;

void start (){
   int ans = 1e9 + 7;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        int a, b;
        scanf("%d %d", &a, &b);
        ans = min (ans, a);
        o[i] = ob(a,b);
    }
    cl[0] = 1e9 + 7;
    sort(o + 1, o + 1 + n);
    for (int i = 1; i <= n; ++i){
        s[i] = s[i - 1] + o[i].b;
        cl[i] = min (o[i].a - o[i].b, cl[i-1]);
    }
    f[n] = o[n].a;
    for (int i = n - 1; i > 0; --i){
        f[i] = min (f[i + 1], o[i].a);
    }
    printf("%d\n", ans);
}

void solve (ll t){
    ll ans = s[t- 1];
    ans += f[t];
    ans = min (ans, s[t] + cl [t]);
    printf("%lld\n", ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("TEAM.INP", "r", stdin);
    freopen("TEAM.OUT", "w", stdout);
    start();
    for (int i = 2; i <= n; ++i){
        solve(i);
    }
    return 0;
}
