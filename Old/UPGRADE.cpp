#include <iostream>
#include <cstdio>

struct edge {
    int x, y, c;
    edge (int _x = 0, int _y = 0, int _c = 0){
        x = _x;
        y = _y;
        c = _c;
    }
};

const int N = 1e5 + 7;
edge a[N];
int head [N], adj [2*N], m, n, low[N], num[N], ans = 0, ac = 0;

using namespace std;

void start (){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        a[i] = edge(x, y, c);
        head[x]++;
        head[y]++;
    }
    for (int i = 1; i <= n; ++i) {
        head[i] += head[i - 1];
        num[i] = 0;
    }
    for (int i = 1; i <= m; ++i){
        int x = a[i].x, y = a[i].y;
        adj[head[x]] = y;
        adj[head[y]] = x;
        head[x]--;
        head[y]--;
    }
}

void visit (int u){
    ac++;
    num[u] = ac;
    low[u] = n + 1;
    for (int i = head[u] + 1; i <= head[u + 1]; ++i){
        int v = adj[i];
        if (num[v] == 0){
            visit(v);
            if (low[v] > num[u]) {
                    ans++;
            }
            low[u] = min (low[u], low[v]);
        } else low[u] = min (low[u], num[v]);
    }
}

int main(){
    start();
    for (int i = 1; i <= n; ++i){
        if (num[i] == 0) visit(i);
    }
    cout << ans;
    return 0;
}
