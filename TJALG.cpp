#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

struct edge {
    int u, v;
};

const int  N = 1e4 + 1, M = 1e5 + 1;
int num [N], low [N], head [N], adj [M], n, m, c, ans;
edge a[M];
bool f [N];
stack <int> st;

void start (){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a[i].u >> a[i].v;
        head [a[i].u]++;
    }
    for (int i = 2; i <= n; ++i) head [i] += head[i-1];
    for (int i = 1; i <= m; ++i){
        adj [head[a[i].u]] = a[i].v;
        head [a[i].u]--;
    }
    c = 0;
    ans = 0;
    for (int i = 1; i <= n; ++i){
        f [i] = true;
        num [i] = 0;
        low [i] = 0;
    }
}

void visit (int u){
    c++;
    num[u] = c;
    low[u] = num[u];
    st.push(u);
    for (int i = head [u] + 1; i <= head [u+1]; ++i){
        int v = adj[i];
        if (!f[v]) continue;
        if (num[v] != 0) low [u] = min (low[u], num[v]);
        else {
            visit(v);
            low [u] = min (low[u], low[v]);
        }
    }
    if (num [u] == low[u]){
        ans++;
        int v = u-1;
        while (u != v){
            v = st.top();
            st.pop();
            f[v] = false;
        }
    }
}

int main (){
    freopen("TJALG.INP", "r", stdin);
    freopen("TJALG.OUT", "w", stdout);
    start();
    for (int i = 1; i <= n; ++i){
        if (num[i] == 0) visit (i);
    }
    cout << ans;
    return 0;
}
