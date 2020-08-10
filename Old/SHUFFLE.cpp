#include <cstdio>

using namespace std;

struct card {
    int id, n, p;
    card (int _p = 0, int _id = 0, int _n = 0){
        id = _id;
        n = _n;
        p = _p;
    }
};

const int N = 1e5 + 7;
card a[N];
int n, x;

void start (){
    scanf ("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i){
        a[i] = card (i - 1, i , i + 1);
    }
}

int del (int u){
    for (int i = 1; i <= n; ++i){
        if (a[i].id == u) {
                u = i;
                break;
        }
    }
    int s = a[u].p;
    int t = a[u].n;
    a[s].n = a[t].id;
    a[t].p = a[s].id;
    a[u] = card (0, a[u].id , 0);
    return u;
}

void add (int u, int v){
    for (int i = 1; i <= n; ++i){
        if (a[i].id == v){
            v = a[i].id;
            break;
        }
    }
    a[u] = card (a[v].p, a[u].id, a[v].id);
    int p = a[v].p;
    a[p] = card (a[p].p,a[p].id, u);
    a[v] = card (a[u].id, a[v].id, a[v].n);
}

int main(){
    start();
    for (int i = 1; i <= x; ++i){
        int u, v;
        scanf ("%d%d", &u, &v);
        u = del (u);
        add (u, v);
    }
    int u;
    for (int i = 1; i <= n; ++i){
        if (a[i].p == 0) {
                u = i;
                break;
        }
    }
    while (n > 0){
        printf("%d ", a[u].id);
        u = a[u].n;
        n--;
    }
    return 0;
}
