#include <iostream>

using namespace std;

const int N = 300 + 1;
int a[N][N], n, k, s;
bool ok[N];

void start (){
    s = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            s = max (s, a[i][j]);
        }
    }
}

void DFS (int u, int ac){
    ok[u] = false;
    for (int v = 1; v <= n; ++v){
        if (!ok[v]) continue;
        if (a[u][v] < ac) DFS (v, ac);
    }
}

int BS (int l, int r){
    int g, ans = 0;
    while (l <= r){
        g = (l + r)/2;
        int s = 0;
        for (int i = 1; i <= n; ++i) ok[i] = true;
        for (int i = 1; i <= n; ++i) if (ok[i]) {
            DFS (i, g);
            s++;
        }
        if (s >= k) {
            ans = g;
            l = g + 1;
        }
        else {
            r = g - 1;
        }
    }
    return ans;    
}

int main (){
    start ();
    cout << BS (0, s) << endl;
    return 0;
}