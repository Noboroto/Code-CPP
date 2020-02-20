#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int u, v, c;
    edge (int _u = 0, int _v = 0, int _c = 0){
        u = _u;
        v = _v;
        c = _c;
    }
};

long long oo = 1e9+7;
int n;
vector <int> head;
vector <long long> d, f;
vector <bool> ok;
vector <edge> a, adj;

void start () {
    int m;
    cin >> n >> m;
    head.push_back(-1);
    for (int i = 1; i <= n; ++i) head.push_back(0);
    for (int i = 0; i < m; ++i){
        int k, u, v, c;
        cin >> k >> u >> v >> c;
        u--;
        v--;
        a.push_back(edge(u,v,c));
        adj.push_back(0);
        head[u]++;
        if (k == 2){
            a.push_back(edge (v,u,c));
            head[v]++;
            adj.push_back(0);
        }
    }
    for (int i = 0; i <= n; ++i){
        d.push_back(oo);
        ok.push_back (true);
        if (i != 0) head[i] += head[i-1];
        f.push_back(0);
    }
    d[0] = 0;
    f[0] = 1;
    for (unsigned int i = 0; i < a.size(); ++i){
        int u = a[i].u;
        int v = a[i].v;
        int c = a[i].c;
        adj[head[u]] = edge(u,v,c);
        head[u]--;
    }
}

void Dijkstra (){
    while (true){
        int u = -1;
         for (int v=0; v<n; v++) if (ok[v]) {
            if (u == -1 || d[u] > d[v]) u = v;
        }
        if (u == -1) break;
        ok [u] = false;
        if (u == n) break;
        for (int i = head[u] + 1; i <= head[u + 1]; ++i){
            int v = adj[i].v;
            int c = adj[i].c;
            if (ok[v] && d[v] == d[u] + c) f[v] += f[u] ;
            if (!ok[v] || d[v] <= d[u] + c) continue;
            d[v] = d[u] + c;
            f[v] = f[u];
        }
    }
}


int main (){
    start();
    Dijkstra();
    if (f[n-1] == 0) cout << "0 0";
    else cout << d[n-1] << ' ' << f[n-1];
    return 0;
}
