#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct edge {
    int u, v, c;
    edge (int _u = 0, int _v = 0, int _c = 0){
        u = _u;
        v = _v;
        c = _c;
    }
};

long long const oo = 1e18 + 7;
int nHeap, n, m;
vector <long long> d;
vector <int> heap, head, trace, pos;
map <int, bool> ok;
vector <edge> a, adj;

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
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
    {
        heap.push_back(0);
        heap.push_back(0);
        pos.push_back(0);
        trace.push_back(0);
        head.push_back(0);
        head.push_back(0);
        ok[i] = true;
        d.push_back(oo);
    }
    adj.push_back(edge());
    adj.push_back(edge());
    for (int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        a.push_back (edge(u,v,c));
        head[u]++;
        head[v]++;
        adj.push_back(edge());
        adj.push_back(edge());
    }
    nHeap = 0;
    for (int i = 1; i <= n; ++i){
        head[i] += head[i-1];
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
    int f = n;
    int i = 1;
    d[i] = n;
    while (f != 1){
        f = trace[f];
        i++;
        d[i] = f;
    }
    for (;i > 0; --i){
        cout << d[i] << ' ';
    }
}

int main (){
    start();
    Dijkstra();
    getout();
    return 0;
}
