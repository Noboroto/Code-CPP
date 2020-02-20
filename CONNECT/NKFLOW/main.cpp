#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, c;
    edge (int _u = 0, int _v = 0, int _c = 0){
        u = _u;
        v = _v;
        c = _c;
    }
    bool operator < (const edge b){
        if (u < b.u) return true;
        if (u == b.u && v < b.v) return true;
        if (u == b.u && v == b.v && c < b.c) return true;
        return false;
    }
};

const int N = 1000 + 10, oo = 1e9 + 7;
int delta [N], trace [N], head[N], f[N][N];
edge a[N];
int s, t, m, n;

void start (){
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        a[i] = edge (x, y, c);
        a[i + m] = edge (x, y);
        head[x]++;
        head[y]++;
    }
    sort(a + 1, a + 2*n + 1);
    for (int i = 1; i <= n + 1; ++i) head[i] += head[i-1];
}

bool FindPath (){
    queue <int> q;
    int u;
    for (int i = 1; i <= m; ++i) trace[i] = 0;
    trace[s] = oo;
    delta[s] = oo;
    q.push(s);
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (int i = head[u-1] + 1; i <= head[u]; ++i){
            int v = a[i].v;
            if (trace[v] == 0) {
                if (f[u][v] < a[i].c) {
                    trace[v] = i;
                    delta[v] = min (delta[u], a[i].c - f[u][v]);
                } else if (f[v][u] > 0){
                    trace[v] = -i;
                    delta[v] = min (delta[u], f[v][u]);
                }
                if (trace[v] != 0){
                    if (v == t) return true;
                    q.push(v);
                }
            }
        }
    }
    return false;
}

void IncFlow (){
    int IncValue = delta[t];
    int v = t;
    while (v != s){
        int i = trace[v];
        int u = a[i].u;
        if (trace[v] > 0) f[u][v] += IncValue;
        else f[v][u] -= IncValue;
        v = u;
    }

}

int main(){
    start();
    while (true){
        if (!FindPath()) break;
        IncFlow();
    }
    int ans = 0;
    for (int i = head[s - 1] + 1; i <= head[s]; ++i){
        int v = a[i].v;
        ans += f[s][v];
    }
    cout << ans;
    return 0;
}
