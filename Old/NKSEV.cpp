#include <iostream>
#include <cstdio>

using namespace std;

struct node {
    int u;
    node *c[26];
};

const int abc = 97;
const int ABC = 65;
const int N = 300000;
int f [N], n;
char s[N], a[N];
node *root;

void make (node *p){
    p = new node;
    p->u = 0;
    for (int i = 0; i < 26; ++i)
        p->c[i] = NULL;
}

void add (int n){
    node *p = root;
    for (int i = 0; i < n; ++i){
        int c = (int) a[i];
        if (p->c[c] == NULL) make(p);
        p = p->c[c];
        p -> u++;
    }
}

void start (){
    char c = 'a';
    int m, i = -1;
    while (c != '\0'){
        cin >> c;
        s[++i] = c;
    }
    n = i;
    cin >> m;
    for (int j = 1; j <= m; ++j){
        i = 0;
        while (c != '\0'){
            cin >> c;
            a[++i] = c;
        }
        int b = i;
        add(b);
    }
}

int main(){
    freopen("NKSEV.INP", "r", stdin);
    freopen("NKSEV.OUT", "w", stdout);
    make (root);
    start();
    return 0;
}
