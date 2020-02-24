#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

struct node {
    int v, id;
    node (int _v = 0, int _id = 0){
        v = _v;
        id = _id;
    }
};
const int N = 2*1e5 + 7, oo = 1e9 + 7;
int a[N], n, m;
node st[4*N];
stack <node> sta;

node min (node a, node b){
    if (a.v < b.v) return a;
    else return b;
}

void del (int id, int l, int r, int i){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = node(oo, i);
        return;
    }
    int mid = (l + r) / 2;
    int a = id * 2;
    del (a, l, mid, i);
    del (a + 1, mid + 1, r, i);
    st[id] = min (st[a], st[a + 1]);
}

void add (int id, int l, int r, int i, int k){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = node(k, i);
        return;
    }
    int mid = (l + r) / 2;
    int a = id * 2;
    add (a, l, mid, i, k);
    add (a + 1, mid + 1, r, i, k);
    st[id] = min (st[a], st[a + 1]);
}

node getout (int id, int l, int r, int u, int v){
    if (v < l || r < u) return node(oo);
    if (u <= l && r <= v){
        return st[id];
    }
    int mid = (l + r)/2;
    int a = id * 2;
    node la = getout(a,l,mid,u, v);
    node ra = getout(a + 1, mid + 1, r, u, v);
    return min (la, ra);
}

void start() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        add (1,1,n,i,a[i]);
    }
}

int solve (int l, int r, int t){
    node s = getout(1,1,n,l,r);
    del(1,1,n,s.id);
    sta.push(s);
    int ab = 0;
    int ans = t % s.v;
    while (ab <= t){
        node tmp = getout(1,1,n,l,r);
        del(1,1,n,tmp.id);
        sta.push(tmp);
        ab = t / s.v - 1;
        ab = ab * s.v + tmp.v;
        ans = min(ans, t % ab);
    }
    while (!sta.empty()){
        node tmp = sta.top();
        sta.pop();
        add (1,1,n,tmp.id,tmp.v);
    }
    return ans;
}

int main(){
    //freopen("SHOPPING.INP", "r", stdin);
    //freopen("SHOPPING.OUT", "w", stdout);
    start();
    for (int i = 1; i <= m; ++i){
        int t, u, v;
        scanf("%d%d%d", &t, &u, &v);
        int ans = solve(u,v,t);
        printf("%d\n", ans);
    }
    return 0;
}
