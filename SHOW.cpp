#include <iostream>

struct node {
    int m;
    long long n;
};

const int oo = 1e9;
const int N = 1e5;
long long k;
int n;
node st [4*N];

void update (int id, int l, int r, int i, int v){
    if (i < l || r < i) return;
    if (l == r){
        st[id].m = v;
        st[id].n = v;
        return;
    }
    int mid  = (l + r) / 2;
    update(id*2,l, mid, i, v);
    update(id*2+1,mid+1,r, i,v);
    st [id].m = std::min (st[id*2].m, st[id*2+1].m);
    st [id].n = st[id*2].n + st[id*2+1].n;
}

node get (int id, int l, int r, int u, int v){
    node g;
    g.m = oo;
    g.n = 0;
    if (v < l || r < u) return g;
    if (u <= l && r <= v){
        g = st[id];
        return g;
    }
    node z, t;
    int mid = (l + r) / 2;
    z = get(id*2,l, mid, u, v);
    t = get(id*2+1, mid + 1, r, u, v);
    g.m = std::min (z.m, t.m);
    g.n = z.n + t.n;
    return g;
}

int start (){
    std::cin >> n >> k;
    int v;
    for (int i = 1; i <= n; ++i){
        std::cin >> v;
        update(1,1,n,i,v);
    }
    return 0;

}

int solve (){
    long long s = 0;
    node g;
    for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j){
        g = get (1, 1, n, i, j);
        if (g.m + g.n <= k) s++;
    }
    std::cout << s;
    return 0;
}

int main (){
    start();
    solve();
    return 0;
}
