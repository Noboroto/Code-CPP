#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int u, v, id;
    edge (int _u = 0, int _v = 0, int _id = 0){
        u = _u;
        v = _v;
        id = _id;
    }
    bool operator < (edge b){
        return u < b.u;
    }
};

const int N = 500000;
int a[N], f[N], n, m, b[N];
vector <edge> s;

void solve (){
    sort (s.begin(), s.end());
    int ll = (s[0].u + s[0].v)/2, lr = ll + 1;
    for (unsigned int i = 0; i < s.size(); ++i){
        int l = s[i].u, r = s[i].v, ma = 0, id = 0;
        while (ll > l){
            int x = a[ll];
            f[x]++;
            ll--;
            if (ma < f[x]){
                ma = f[x];
                id = x;
            }
        }
        while (ll < l){
            int x = a[ll];
            f[x]--;
            ll++;
            if (ma < f[x]){
                ma = f[x];
                id = x;
            }
        }
        while (lr > r){
            int x = a[lr];
            f[x]--;
            lr--;
            if (ma < f[x]){
                ma = f[x];
                id = x;
            }
        }
        while (lr < r){
            int x = a[lr];
            f[x]++;
            lr++;
            if (ma < f[x]){
                ma = f[x];
                id = x;
            }
        }
        b[i] = id;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= m; ++i){
        int l, r;
        scanf("%d%d", &l, &r);
        s.push_back(edge(l,r,i));
    }
    solve();
    for (int i = 1; i <= m; ++i)
        printf("%d\n", b[i]);
    return 0;
}
