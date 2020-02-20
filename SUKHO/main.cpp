#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100, M = 10000;
int n, m, k, a[N], f[M];

void start (){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
}

void solve (){
    f[0] = 1;
    for (int j = 1; j <= m; ++j){
        for (int i = 1; i <= n; ++i){
            if (j - a[i] <= 0) break;

        }
    }
}

int main(){
    start();
    solve();
    return 0;
}
