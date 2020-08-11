#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 7;
int a[N], n, m;

void start (){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
}

int bs (int x){
    int l = 1, r = n, g, id = 0;
    while (l <= r){
        g = (l + r) / 2;
        if (a[g] == x) {
            id = g;
            break;
        }
        if (a[g] < x) l = g + 1;
        if (a[g] > x) r = g - 1;
    }
    if (id == 0) return 0;
    g = 0;
    for (int i = id; i > 0; --i){
        if (a[i] != x) break;
        g++;
    }
    for (int i = id + 1; i <= n; ++i){
        if (a[i] != x) break;
        g++;
    }
    return g;
}

int main(){
    freopen("FOUND2.INP", "r", stdin);
    freopen("FOUND2.OUT", "w", stdout);
    start();
    for (int i = 1; i <= m; ++i){
        int x;
        cin >> x;
        cout << bs(x) << endl;
    }
    return 0;
}
