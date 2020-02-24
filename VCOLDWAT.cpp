#include <cstdio>
#include <algorithm>

using namespace std;

struct node{
    int u, v;
    node (int _u = 0, int _v = 0){
        u = _u;
        v = _v;
    }
};

const int N = 100000;
int s [N], n, c, t[N];
node a[2*N];

bool comp (node a, node b){
    return a.u < b.u;
}

void start (){
    scanf("%d%d", &n,&c);
    s[1] = 1;
    for (int i = 1; i <= c; ++i){
        int b1, b2, e;
        scanf("%d%d%d", &e,&b1,&b2);
        a[i] =  node (e, b1);
        a[i + c] = node (e, b2);
    }
    sort(a + 1, a + 1 + 2*c, comp);
    int k = a[1].u;
    for (int i = 2; i <= 2*c; ++i){
        if (a[i].u != k){
            t[k] = i - 1;
            k = a[i].u;
        }
    }
    t[k] = c*2;
}

void dfs (int f){
    for (int i = t[f - 1] + 1; i <= t[f]; ++i){
        if (a[i].u == f){
            int j = a[i].v;
            s[j] = s[f] + 1;
            dfs(j);
        }
    }
}

int main()
{
    start();
    dfs(1);
    for (int i = 1; i<= n; ++i){
        printf("%d\n", s[i]);
    }
    return 0;
}
