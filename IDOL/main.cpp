#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct query {
    int u, v, k;
};

const int Q = 500;
const int N = 50;
const int oo = 1e9;
int st [4*N], n, q;
query sk[Q];

void update (int id, int l, int r, int u, int v, int k){
    if (v < l || r < u) return;
    if (u <= l && r <= v){
        if (st[id] == 0 || st[id] == oo) st[id] = k;
        st [id] = max (st[id], k);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,k);
    update(id*2+1,mid+1,r,u,v,k);
    st [id] = min (st[id*2], st[id*2+1]);
}

int get (int id, int l, int r, int u, int v){
    if (v < l || r < u) return -oo;
    if (u <= l && r <= v){
        return st[id];
    }
    int mid = (l + r) / 2;
    return max (get(id*2,l,mid,u,v), get(id*2+1,mid + 1, r,u,v));
}

void start(){
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) update(1,1,n,i,i,oo);
    for (int i = 1; i <= q; ++i){
        cin >> sk[i].u >> sk[i].v >> sk[i].k;
        update(1,1,n,sk[i].u,sk[i].v,sk[i].k);
    }
}

int main(){
    freopen("IDOL.INP", "r", stdin);
    freopen("IDOL.OUT", "w", stdout);
    start();
    return 0;
}
