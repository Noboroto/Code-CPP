#include <iostream>
#include <cstdio>

using namespace std;

struct node {
    int u, f;
    node *c[2];
};

const int N = 10000;
int s[N];
node root;
int n, m;

node* make (node *p){
    p = new node;
    p -> u = 0;
    p -> f = 0;
    for (int i = 0; i < 2; ++i){
        p -> c[i] = NULL;
    }
    return p;
}

void add (int n){
    node *p = &root;
    for (int i = 0; i < n; ++i){
        int c = s[i];
        if  (p -> c[c] == NULL) p-> c[c] = make(p -> c[c]);
        p = p -> c[c];
        p -> f++;
    }
    p -> u++;
}

void start (){
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j){
            cin >> s[j];
        }
        add(k);
    }
}

int solve (node * p, int i, int n){
    if (p == NULL) return 0;
    int f = 0;
    if (i >= n) {
        f += p -> f;
    }
    else {
        f = solve (p -> c[s[i]], i + 1, n);
        f += p->u;
    }
    return f;
}

int main()
{
    freopen("SEC.INP", "r", stdin);
    freopen("SEC.OUT", "w", stdout);
    start();
    for (int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j){
            cin >> s[j];
        }
        cout << solve (root.c[s[0]], 1, k) << endl;
    }
    return 0;
}
