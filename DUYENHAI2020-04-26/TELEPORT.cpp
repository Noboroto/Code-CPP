#include <iostream>
#include <cstdio>

using namespace std;

struct edge {
    int u, v, c;
    edge (int _u = 0, int _v = 0, int _c = 0){
        u = _u;
        v = _v;
        c = _c;
    }
};

int const N = 1e6 + 1, oo = 1e9 + 77;
int heap [2*N], nHeap, n, m, pos[N], head[2*N], trace[N], l, k, p;
long long d[N];
bool ok [N];
edge a[N], adj [N];

void update (int v){
    int c = pos[v];
    if (c == 0){
        nHeap++;
        c = nHeap;
    }
    int p = c / 2;
    while (p > 0 && d[heap[p]] >= d[v]){
        heap[c] = heap[p];
        pos[heap[c]] = c;
        c = p;
        p = c/2;
    }
    heap[c] = v;
    pos[v] = c;
}

int pop (){
    int p = heap[1];
    int v = heap [nHeap];
    nHeap--;
    if (nHeap == 0) return p;
    int r = 1;
    while (r*2 <= nHeap){
        int c = r*2;
        if (c < nHeap && d[heap[c+1]] < d[heap[c]])c++;
        if (d[v] <= d[heap[c]]) break;
        heap[r] = heap[c];
        heap[c] = 0;
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return p;
}


void start () {
    cin >> n >> m >> l >> k >> p;
    for (int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        a[i] = edge(u,v,c);
        head[u]++;
        head[v]++;
    }nHeap = 0;
    for (int i = 1; i <= n; ++i){
        pos[i] = 0;
        d[i] = oo;
        ok[i] = true;
        head[i] += head[i-1];
        trace[i] = 0;
        if (i > 1) update(i);
    }
    d[1] = 0;
    for (int i = 0; i < m; ++i){
        int u = a[i].u;
        int v = a[i].v;
        int c = a[i].c;
        adj[head[u]] = edge(u,v,c);
        adj[head[v]] = edge(v,u,c);
        head[u]--;
        head[v]--;
    }

}

void Dijkstra (){
    update(1);
    while (nHeap > 0){
        int u = pop();
        ok [u] = false;
        if (u == n) break;
        for (int i = head[u] + 1; i <= head[u + 1]; ++i){
            int v = adj[i].v;
            int c = adj[i].c;
            if (!ok[v] || d[v] <= d[u] + c) continue;
            d[v] = d[u] + c;
            trace [v] = u;
            update(v);
        }
    }
}

void getout (){
    if (d[n] == oo && trace[n] == 0){
        cout << -1;
        return;
    }
    cout << d[n];
}

int main (){
    start();
    Dijkstra();
    getout();
    return 0;
}