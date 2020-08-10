#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct edge {
    int x, y;
    edge (int _x = 0, int _y = 0){
        x = _x;
        y = _y;
    }
};

int const N = 2e5 + 1;
edge a[N], adj[2*N];
int n, m, head[N], low[N], num[N], c, nc[N], s;
bool mark[N];
vector <edge> ans;

void start (){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = edge (x, y);
        head[x]++;
        head[y]++;
    }
    for (int i = 1; i <= n + 1; ++i){
        head[i] += head[i - 1];
        low[i] = 1e9 + 7;
        num[i] = 0;
    }
    c = 0;
    for (int i = 1; i <= m; ++i){
        int x = a[i].x, y = a[i].y;
        adj[head[x]] = edge (y, head[y]);
        adj[head[y]] = edge (x, head[x]);
        head[x]--;
        head[y]--;
    }
}

void visit (int u){
    c++;
    num[u] = c;
    nc[u] = 0;
    mark[u] = false;
    for (int i = head[u] + 1; i <= head[u + 1]; ++i){
        if (adj[i].x == 0) continue;
        int v = adj[i].x;
        adj[adj[i].y].x = 0;
        if (num [v] == 0){
            nc[u]++;
            visit(v);
            if (low [v] > num [u]) {
                   ans.push_back(edge(u,v));
            }
            mark[u] = mark[u] || low[v] >= num[u];
            low[u] = min (low [u], low[v]);
        } else low[u] = min (low[u], num[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    freopen("CUT.INP", "r", stdin);
    freopen("CUT.OUT", "w", stdout);
    s = 0;
    start();
    for (int i = 1; i <= n; ++i){
        if (num[i] == 0) {
            visit(i);
            if (nc[i] < 2) {
                    mark[i] = false;
            }
        }
        if (mark[i]) s++;
    }
    printf("%d %d\n", ans.size(), s);
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d %d\n", ans[i].x, ans[i].y);
    }
    for (int i = 1; i <= n; ++i){
        if (mark[i]) printf("%d\n", i);
    }
    return 0;
}
