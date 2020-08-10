#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e5 + 7, oo = 1e9 + 7;
int st [4*N], n, m;

void add (int id, int l, int r, int i, int k){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = k;
        return;
    }
    int mid = (l + r) / 2;
    int a = id * 2;
    add (a, l, mid, i, k);
    add (a + 1, mid + 1, r, i, k);
    st[id] = min (st[a], st[a + 1]);
}

int getout (int id, int l, int r, int u, int v){
    if (v < l || r < u) return oo;
    if (u <= l && r <= v){
        return st[id];
    }
    int mid = (l + r)/2;
    int a = id * 2;
    int la = getout(a,l,mid,u, v);
    int ra = getout(a + 1, mid + 1, r, u, v);
    return min (la, ra);
}

void start (){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        int x;
        scanf("%d", &x);
        add (1,1,n,i,x);
    }
}

int main(){
    freopen("RMQ.INP", "r", stdin);
    freopen("RMQ.OUT", "w", stdout);
    start();
    for (int i = 1; i <= m; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        int ans = getout(1,1,n,u,v);
        printf("%d\n", ans);
    }
    return 0;
}
