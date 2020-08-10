#include <iostream>
#include <cstdio>
using namespace std;

const int N = 50000;
const int oo = 1e9 + 7;
int st [4*N];
int n, m, ans;

void update (int id, int l, int r, int i, int v){
    if (i < l || r < i) return;
    if (l == r) {
        st[id] = v;
        st[id] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2, l, mid,i,v);
    update(id*2+1, mid + 1, r, i, v);

    st [id] = st[id*2] + st [id*2+1];
}

int get (int id, int l, int r, int u, int v){
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r)/2;
    int s = get (id*2, l, mid, u, v) + get (id*2+1, mid + 1, r, u, v);
    return s;
}
void start (){
    cin >> n;
    int c;
    for (int i = 1; i <= n; ++i){
        cin >> c;
        update(1,1,n,i,c);
    }
    cin >> m;
}

int main()
{
    freopen("GSS.INP", "r", stdin);
    freopen("GSS.OUT", "w", stdout);
    start();
    int x, y;
    for (int k = 1; k <= m; ++k){
        cin >> x >> y;
        int ans = -oo;
        for (int i = x; i <= y; ++i){
            for (int j = i; j<= y; ++j){
                int c = get(1,1,n,i,j);
                ans = max (ans, c);
            }
        }
        cout << ans<< endl;
    }
    return 0;
}
