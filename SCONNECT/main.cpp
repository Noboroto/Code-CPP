#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct edge {
    int u, v;
    edge (int _u = 0, int _v = 0){
        u = _u;
        v = _v;
    }
};

const int N = 1e6;
int n, m, head [N];
edge adj [N], a[N];
stack <int> s;
int num [N], low [N], c = 0;
bool ok[N];

void start (){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        a[i] = edge (u, v);
        head[u]++;
    }
    for (int i = 1; i <= n + 1; ++i){
        head[i] += head[i-1];
        ok[i] = true;
    }
    for (int i = 1; i <= m; ++i){
        int u = a[i].u;
        adj[head[u]] = a[i];
        head[u]--;
    }
}

void visit (int u){
    c++;
    num[u] = c;
    low[u] = c;
    s.push(u);
    for (int i = head[u] + 1; i <= head[u + 1]; ++i){
        int v = adj[i].v;
        if (!ok[v]) continue;
        if (num[v] == 0){
            visit(v);
            low[u] = min (low[u], low[v]);
        } else low [u] = min (low [u], num[v]);
    }
    if (num[u] == low [u]){
        int x = 0;
        while (x != u && !s.empty()){
            x = s.top();
            s.pop();
            ok[x] = false;
            cout << x << ' ';
        }
        cout << endl;
    }
}

int main(){
    freopen("SCONNECT.INP", "r", stdin);
    freopen("SCONNECT.OUT", "w", stdout);
    start();
    for (int i = 1; i <= n; ++i){
        if (num[i] == 0) visit(i);
    }
    return 0;
}
