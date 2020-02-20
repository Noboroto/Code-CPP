#include <iostream>

using namespace std;

struct node{
    int u, v;
    node *c[2];
};
node root;
int s[30], n;

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
    for (int i = 0; i < 30; ++i){
        int c = s[i];
        if (p -> c[c] == NULL) p -> c[c] = make(p -> c[c]);
        p = p-> c[c];
    }
    p -> u = t;
    p -> v++;
}

void transbit (int x){
    for (int i = 29; i >= 0; --i){
        s[i] = x & 1;
        x = x >> 1;
    }
}

node* remov (node *p, int i){
    if (i < 30) {
            int c = s[i];
            if (p -> c[c] == NULL) return p;
            p -> c[c] = remov(p -> c[c],i + 1);
    }
    if (i == 30) p-> v--;
    return p;
};

int solve (node *p, int i){
    if (p == NULL) return 0;
    if (i > 29){
        if (p -> v == 0) return 0;
        return p -> u;
    }
    int a, c;
    if (s[i] == 0) c = 1;
    else c = 0;
    if (p -> c[c] != NULL) a = solve(p -> c[c], i + 1);
    else a = solve (p -> c [c ^ 1], i + 1);
    if (a == 0) a = solve(p -> c [c ^ 1], i + 1);
    return a;
}

int main()
{
    make(&root);
    cin >> n;
    int k;
    for (int i = 1; i <= n; ++i){
        char a[2], c;
        cin.getline(a,1);
        cin >> c;
        cin >> k;
        transbit(k);
        if (c == '+') add(k);
        if (c == '-') remov(&root, 0);
        if (c == '?') {
            int d = solve(&root, 0);
            k = max (k ^ d, k ^ 0);
            cout << k << endl;
        }
    }
    return 0;
}
