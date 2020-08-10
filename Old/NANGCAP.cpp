 #include <iostream>
#include <cstdio>
#include <algorithm>+

using namespace std;

struct edge {
    int x, y, c;
    edge (int _x = 0, int _y = 0, int _c = 0){
        x = _x;
        y = _y;
        c = _c;
    }
    bool operator < (const edge b){
        return c > b.c;
    }
};

const int N = 1e5 + 10;
edge a[N];
int n, m, root [N];
long long ans = 0;

void start (){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        a[i] = edge (x, y, c);
        ans += c;
    }
    for (int i = 1; i <= n; ++i) {
        root [i] = -1;
    }
    sort(a + 1, a + 1 + m);
}

int getroot (int v){
    while (root [v] > 0) v = root[v];
    return v;
}

void gattai (int r1, int r2){
    int sum = root[r1] + root[r2];
    if (r1 > r2){
        root[r2] = sum;
        root[r1] = r2;
    } else {
        root[r1] = sum;
        root[r2] = r1;
    }
}

void Kruskal (){
    int co = 0;
    for (int i = 1; i <= m ; ++i){
        if (co >= n - 1) break;
        int r1 = getroot(a[i].x);
        int r2 = getroot(a[i].y);
        if (r1 != r2){
            co++;
            ans -= a[i].c;
            gattai(r1, r2);
        }
    }
    cout << ans;
}



int main(){
    start();
    Kruskal();
    return 0;
}
