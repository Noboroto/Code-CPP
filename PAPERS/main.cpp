#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

const int N = 1e5 + 1, oo = 1e9 + 7, M = 1e9 + 1;
int a [N], t = 0, m, n;
int f[N][N];

void start(){
    cin >> m >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

void solve (int i, int s){
    if (i > n){
        if (s != m) return;
        t++;
        t %= oo;
        return;
    }
    for (int j = a[i]; j <= m - a[i]; ++j){
        solve(i + 1, s + j);
    }
}

int main(){
    freopen("PAPERS.INP", "r", stdin);
    freopen("PAPERS.OUT", "w", stdout);
    start();
    solve(1,0);
    cout << t;
    return 0;
}
