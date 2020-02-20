#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 3e4 + 7;
const int maxk = 2e5 + 7;

struct Query {
    int i, j, k, id;
    bool operator < (const Query& b){
        return k < b.k;}
};
int b[maxk], st [maxn], n, q;
Query sk [maxk];
pair <int, int> a[maxn];

int update (int i){
    while (i <= n){
        st [i]++;
        i += i & (-i);
    }
    return 0;
}

int get (int i){
    int g = 0;
    while (i > 0) {
        g += st[i];
        i -= i & (-i);
    }
    return g;
}

int start (){
    scanf("%d", &n);
    for (int i = 1; i<= n; ++i){
        scanf("%d",&a[i].first);
        a[i].second = i;
    }
    scanf("%d",&q);
    for (int i = 1; i <= q; ++i){
        scanf("%d%d%d",&sk[i].i,&sk[i].j,&sk[i].k);
        sk[i].id = i;
    }
    sort(a + 1, a + n + 1);
    sort(sk + 1, sk + q + 1);
    return 0;
}

int main (){
    start();
    int j = n;
    for (int i = q; i > 0; --i){
        while (sk[i].k < a[j].first){
            update(a[j--].second);
        }
        b[sk[i].id] = get(sk[i].j) - get (sk[i].i - 1);
    }
    for (int i = 1; i <= q; ++i) printf("%d\n",b[i]);
    return 0;
}
