#include <cstdio>
#include <iostream>
 
using namespace std;
 
int const N = 1000 + 1;
long long m, n, f[N][N];
 
int main () {
    cin >> m >> n;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            cin >> f[i][j];
        }
    }
    for (int j = 1; j < n; ++j) {
        for (int  i = 0; i < m; ++i){
            int x = (i - 1 < 0) ? -1e9: f[i - 1][j - 1];
            int y = f[i][j - 1];
            int z = (i + 1 >= n) ? -1e9: f[i + 1][j - 1];
            f[i][j] = f[i][j] + max (x, max (y, z));
        }
    }
    long long ans = -1e9;
    for (int i = 0; i < m; ++i) ans = max (ans, f[i][n - 1]);
    cout << ans;
    return 0;
}