#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int cnt;
struct edge {
    int u, v;
    edge (int _u = 0, int _v = 0){
        u = _u;
        v = _v;
    }
};

const int N = 1e6 + 10;
int n, m, head [N];
edge adj [2*N], a[N];
vector <int> ans;
bool ok[N];

void start (){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        a[i] = edge (u, v);
        head[u]++;
        head[v]++;
    }
    for (int i = 1; i <= n + 1; ++i){
        head[i] += head[i-1];
        ok[i] = true;
    }
    for (int i = m; i > 0; --i){
        int u = a[i].u, v = a[i].v;
        adj[head[u]] = a[i];
        adj[head[v]] = edge(v, u);
        head[u]--;
        head[v]--;
    }
    ans.push_back(0);
    ans.push_back(0);
}

void visit (int u){
    cnt++;
    ok[u] = false;
    for (int i = head [u] + 1; i <= head[u + 1]; ++i){
        int v = adj[i].v;
        if (!ok[v]) continue;
        visit(v);
    }

}

int main(){
    //freopen("CONNECT.INP", "r", stdin);
    //freopen("CONNECT.OUT", "w", stdout);
    start();
    for (int i = 1; i <= n; ++i){
        if (ok[i]) {
            cnt=0;
            visit(i);
            if (cnt >= ans.back()){
                swap(ans.front(), ans.back());
                ans.pop_back();
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    long long aa = ans[0] + ans[1];
    cout << aa;
    return 0;
}
