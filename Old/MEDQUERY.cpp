#include <cstdio>

using namespace std;

struct node {
    int u, v;
    node *c [2];
};

const int B = 30;
int s[B];
node root;

node *make (node *p){
    p = new node;
    p -> u = 0;
    p -> v = 0;
    p -> c[0] = NULL;
    p -> c[1] = NULL;
    return p;
}

void transbit (int x){
    for (int i = B - 1; i > 0; --i){
        s[i] = x & 1;
        x = x >> 1;
    }
}

void add (int t){
    node *p = &root;
    for (int i = 0; i < B; ++i){
        int c = s[i];
        if (p -> c[c] == NULL) p -> c[c] = make(p -> c[c]);
        p = p -> c[c];
        p -> u++;
    }
    p -> v = t;
}

node *del (node *p, int i){
    if (p == NULL) return p;
    if (i < B){
        int c = s[i];
        p -> c[c] = del(p -> c[c],i + 1);
    }
    if (p == &root) return p;
    p -> u--;
    if (p -> u <= 0){
        delete p;
        p = NULL;
    }
    return p;
}

int solve (node *p, int i, int k){
    if (i >= B){
        if (p == NULL) return 0;
        return p -> v;
    }
    node *l = p -> c[0];
    node *r = p -> c[1];
    int a = 0, c = 0;
    if (l != NULL) c = l -> u;
    if (l != NULL && l -> u >= k){
        a = solve (l, i + 1, k);
    } else a = solve (r, i + 1, k - c);
    return (a);
}

int main (){
    freopen("MEDQUERY.INP", "r", stdin);
    freopen("MEDQUERY.OUT", "w", stdout);
    int k = 0,n = 0, q = 0;
    scanf("%d\n", &q);
    char c;
    make (&root);
    for (int i = 1; i <= q; ++i){
        int x;
        scanf("%c", &c);
        scanf("%d\n", &x);
        transbit(x);
        if (c == '+'){
            add (x);
            n++;
        }
        if (c == '-') {
            del(&root, 0);
            n--;
        }
        k = (n + 1) / 2;
        x = solve(&root,0,k);
        printf("%d\n", x);
    }
    return 0;
}
