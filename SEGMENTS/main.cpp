#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e8 + 7;
int a[N], d[N], n, m;
void start(){
    cin >> n >> m;
    for (int i = 1; i <= n;++i){
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; ++j){
            if (j < 0) a[abs(j)]++;
            else d[abs(j)]++;
        }
    }
}

int main(){
    freopen("SEGMENTS.INP", "r", stdin);
    freopen("SEGMENTS.OUT", "w", stdout);
    start();
    for (int i = 1; i <= m; ++i){
        int x;
        cin >> x;
        if (x < 0) cout << a[abs(x)];
        else cout << d[abs (x)];
        cout << ' ';
    }
    return 0;
}
