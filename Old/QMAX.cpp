#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 20 * 1e4;
const int oo = 1e9 + 7;

struct node {
        int maxt;
        int inc;
};

node t [maxn];

int down (int id){
    int q = t[id].inc;

    t[id*2].maxt += q;
    t[id*2].inc += q;

    t[id*2+1].maxt += q;
    t[id*2+1].inc += q;

    t[id].inc = 0;
    return 0;
}

int update (int id, int l, int r, int u, int v, int c){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v){
        t [id].maxt += c;
        t [id].inc += c;
        return 0;
    }

    down(id);

    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,c);
    update(id*2+1,mid+1,r,u,v,c);

    t[id].maxt = max (t[id*2].maxt, t[id*2+1].maxt);
}

int get (int id, int l, int r, int u, int v){
    if (v < l || r < u) return -oo;
    if (u <= l && r <= v){
        return (t[id].maxt);
    }
    int mid  = (l + r)/2;
    down(id);
    return (max (get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v)));
}

int add (int n){
    int u, v, c;
    cin >> u >> v >> c;
    update(1,1,n,u,v,c);
    return 0;
}

int pro (int n){
    int u, v;
    cin >> u >> v;
    int c = get(1,1,n,u,v);
    cout << c << endl;
    return 0;
}

int main()
{
    freopen("QMAX.INP","r", stdin);
    freopen("QMAX.OUT","w", stdout);
    int n, m, k;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> k;
        if (k == 0) add(n);
        if (k == 1) pro(n);
    }
    return 0;
}
