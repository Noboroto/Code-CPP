#include <iostream>

using namespace std;

struct node{
    int u, v;
    node *c[2];
};
node root;
const int B = 30;
int s[B];

node *make (node *p){
    p = new node;
    p -> u = 0;
    p -> v = 0;
    for (int i = 0; i < 2; ++i)
        p -> c[i] = NULL;
    return p;
}

void add (int t){
    node *p = &root;
    for (int i = 0; i < B; ++i){
        int c = s[i];
        if (p -> c[c] == NULL) p -> c[c] = make(p -> c[c]);
        p = p-> c[c];
    }
    p -> u = t;
    p -> v++;
}

void transbit (int x){
    for (int i = B - 1; i >= 0; --i){
        s[i] = x & 1;
        x = x >> 1;
    }
}

int solve (node *p, int i){
    if (p == NULL) return 0;
    if (i > B-1){
        if (p -> v == 0) return 0;
        return p -> u;
    }
    int c, a = -1;
    if (s[i] == 0) c = 1;
    else c = 0;
    if (p -> c[c] != NULL) a = solve(p -> c[c], i + 1);
    else a = solve (p -> c [c ^ 1], i + 1);
    if (a == -1) a = solve(p -> c [c ^ 1], i + 1);
    return a;
}

int main()
{
    make(&root);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        transbit(x);
        add(x);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> x;
        transbit(x);
        int a = solve(&root, 0);
        x = x^a;
        cout << x << endl;
    }
    return 0;
}
