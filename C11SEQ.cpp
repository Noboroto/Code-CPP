#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int maxn = 3*(1e5 + 1);
const int maxa = 1e8;

int start (int*a, int& n, int& l, int& r){
    int c, s = 0;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) {
            cin >> c;
            s += c;
            a[i] = s;
            a[i + n] = s - l;
            a[i + 2*n] = s - r;
    }
    a[0] = l;
    a[n*3 + 1] = r;
    return 0;
}

int get (int i, int* t){
    int g = 0;
    while (i > 0) {
        g += t[i];
        i -= i & (-i);
    }
    return g;
}

int update (int i, int v,int n, int* t){
    while (i <= n) {
        t[i] += v;
        i += i & (-i);
    }
    return 0;
}

int qsort (int l, int r, int* a, int* p){
    int i = l, j = r, g = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] < g) i++;
        while (a[j] > g) j--;
        if (i <= j) {
            swap(a[i],a[j]);
            swap(p[i],p[j]);
            i++;
            j--;
        }
    }
    if (i < r) qsort(i,r,a,p);
    if (l < j) qsort(l,j,a,p);
    return 0;
}

int compress (int n, int* a){
    int dem = 0, last = 1e9+1;
    int b[n], p [n];
    for (int i = 0; i <= n; ++i){
        b[i] = a[i];
        p[i] = i;
    }
    qsort(0,n,b,p);
    for (int i = 0; i <= n; ++i){
        if (b[i] != last) {
            dem++;
            last = b[i];
        }
        a[p[i]] = dem;
    }
    return 0;
}

int maketest (int*a, int& n, int& l, int& r) {
    FILE f;
    srand(time(NULL));
    n = rand() % 50 + 1;
    cout << n << ' ';
    l = n + 2, r = n + 1;
    while (l > r || l <= 0 ){
        l = rand () % 500 + 1;
        r = rand () % 500 + 1;
    }
    cout << l << ' ' << r << endl;
    for (int i = 1; i <= n; ++i) {
        a[i] = rand () % 500 + 1;
        cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}

int solve (int* a, int* t, int n, int l, int r){
    int k;
    for (int i = n;i > 1; --i){
        update(a[i],1,n,t);
        k += (get (a[i-1 + n], t) - get(a[i-1 + 2*n],t));
    }
    return 0;
}

int main () {
    freopen("C11SEQ.INP","r",stdin);
    freopen("C11SEQ.OUT","w",stdout);
    int a[maxn];
    int n, l, r;
    start(a,n,l,r);
    compress(n*3+1,a);
    int t[maxa];
    r = a[n*3+1];
    l = a[0];
    solve(a,t,n*3,l,r);
    return 0;
}
