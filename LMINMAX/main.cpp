#include <iostream>
#include <cstdio>

using namespace std;


struct node {
    int l, r, mi, ma, ans;
    node (int _l = 0, int _r = 0, int _mi = 1e9 + 7, int _ma = 0){
        l = _l;
        r = _r;
        mi = min (_mi, (int)1e9 + 7);
        ma = max (_ma, 0);
        ans = 1;
    }
    bool operator == (node b){
        bool c = true;
        c = c && (l == b.l) && (r == b.r)
        && (mi == b.mi) && (ma == b.ma);
        //c = c && (ans == b.ans);
        return c;
    }
};

const int N = 1e6;
int k, n;
node st [4*N];
node oo = node (0,0,1e9+7,0);

node uni (node a, node b){
    node c;
    c.l = min (a.l, b.l);
    c.r = max (a.r, b.r);
    c.mi = min (a.mi, b.mi);
    c.ma = max (a.ma,
                 b.ma);
    if (a == node(a.l, a.r)){
        c.mi = b.mi;
        c.ans = b.ans;
        c.ma = b.ma;
    }
    else if (b == node (b.l, b.r)){
        c.ans = a.ans;
        c.ma = a.ma;
        c.mi = a.mi;
    }
    else if (c.ma - c.mi <= k) c.ans = a.ans + b.ans;
    else if (a.ma - a.mi <= k && b.ma - b.mi > k){
        c.ans = a.ans;
        c.ma = a.ma;
        c.mi = a.mi;
    }
    else if (b.ma - b.mi <= k && a.ma - a.mi > k) {
        c.ma = b.ma;
        c.mi = b.mi;
        c.ans = b.ans;
    }
    else if (b.ma - b.mi <= k && a.ma - a.mi <= k) {
        c.ans = max (a.ans, b.ans);
        if (c.ans == b.ans) {
            c.ma = b.ma;
            c.mi = b.mi;
        }
        if
    }
    else c.ans = 1;
    return c;
}

void make (int id, int l, int r){
    st [id] = node(l, r);
    if (l == r) return;
    int mid = (l + r) / 2;
    make (id * 2, l, mid);
    make (id * 2 + 1, mid + 1, r);
}

void add (int id, int l, int r, int i, int c){
    if (i < l || r < i) return;
    if (l == r){
        st[id] = node(l, r, c, c);
        return;
    }
    int mid = (l + r) / 2;
    add (id * 2, l, mid, i, c);
    add (id * 2 + 1, mid + 1, r, i, c);
    st [id] = uni (st[id * 2], st [id * 2 + 1]);
}

node get (int id, int l, int r, int u, int v){
    if (v < l || r < u) return oo;
    if (u <= l && r <= v){
        return st[id];
    }
    int mid = (l + r)/2;
    node a = get (id * 2, l, mid, u, v);
    node b = get (id * 2 + 1, mid + 1, r, u, v);
    return uni (a, b);
}

void start (){
    cin >> n >> k;
    make(1, 1, n);
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        add (1,1,n,i,x);
    }
}

int main(){
    start();
    node x = st [1];
    cout << x.ans;
    return 0;
}
