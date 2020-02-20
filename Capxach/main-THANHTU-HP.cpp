#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5, M = 4;
int m, n, a[M], f[M][N];

void start (){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + m);
}

void solve (){
    for (int i = 1; i <= m; ++i){
        int x = a[i];
        int s = x;
        for
        while (s + x <= n){
            s += x;
            f[x][s]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i){
        ans += f[i][n];
    }
    cout << ans;
}

int main() {
    start();
    solve();
    return 0;
}
