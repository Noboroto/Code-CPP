#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 7e3;
int a[N], n, q;
pair <int, int> h[2*N];
bool f [N];

int gcd (int a, int b){
    for (int i = 2; i <= max (a, b); ++i)
        if ((a % i == 0) && (b % i == 0))
            return i;
    return 1;
}

void start () {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        f[i] = false;
    }
    for (int i = 1; i < n; ++i){
        cin >> h[i].first >> h[i].second;
        h[i + n].first = h[i].second;
        h[i + n].second = h[i].first;
    }
    sort (h + 1, h + 2 * n);
}

int fid (int id){
    if (id > n) return 0;
    int s = 0;
    for (int j = 1; j <= 2*n; ++j){
        if (h[j].first != id) continue;
        int v = h[j].second;
        if (!f[v]) continue;
        if (gcd(a[id], a[v]) == 1) s++;
        f [v] = false;
        s += fid (v);
        f [v] = true;
    }
    return s;
}

int main (){
    for (int i = 1; i <= q; ++i){
        int m, x, y;
        cin >> m;
        if (m == 1) {
            cin >> x >> y;
            a[x] = y;
        }
        if (m == 2){
            cin >> x;
            int s = fid (x);
            cout << s;
        }
    }
    return 0;
}
