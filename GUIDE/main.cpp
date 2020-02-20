#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

struct edge {
    int u, v;
    edge (int _u = 0, int _v = 0){
        u = _u;
        v = _v;
    }
};

const int N = 1e5 + 7;
edge a[N];
int n, m, adj[2*N],head [N], trace[N], ok[N];

void start (){
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        a[i] = edge (u, v);
        head[u]++;
        head[v]++;
    }
    cin >> m;
    for (int i = 1; i <= n + 1; ++i) head[i] += head[i - 1];
    for (int i = 1; i <= n - 1; ++i){
        int u = a[i].u, v = a[i].v;
        adj[head[u]] = v;
        adj[head[v]] = u;
        head[u]--;
        head[v]--;
    }
}

void BFS (int s, int t){
    for (int i = 1; i <= n; ++i) {
        trace[i] = 0;
        ok[i] = true;
    }
    queue <int> q;
    q.push (s);
    ok[s] = false;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = head[u] + 1;  i <= head[u + 1]; ++i){
            int v = adj[i];
            if (!ok[v]) continue;
            trace[v] = u;
            ok[v] = false;
            q.push (v);
        }
    }
}

int GetAns (int s, int t){
    int x = trace[t];
    if (x == s) return t;
    while (x != s){
        if (trace[x] == s) break;
        x = trace[x];
    }
    return x;
}

int main (){
    freopen ("GUIDE.INP", "r", stdin);
    //freopen ("GUIDE.OUT", "w", stdout);
    start();
    for (int i = 1; i <= m; ++i){
        int s, t;
        cin >> s >> t;
        BFS(s, t);
        cout << GetAns (s, t) << endl;
    }
    return 0;
}
