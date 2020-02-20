#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1001;
int n, m, a[N][N], t;
bool ok[N][N];

void start (){
    cin >> n >> m;
    t = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            t = max (t, a[i][j]);
            ok[i][j] = true;
        }
    }
}

int solve (){
    int s = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == t)
        }
    }
    return s;
}

int main(){
    start();
    cout << solve();
    return 0;
}
