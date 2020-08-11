#include <iostream>
#include <cstring>

using namespace std;

struct node {
    int u;
    node *c [26];
};

const int N = 250000;
node root;
char s [N];

node* make (node *p){
    p = new node;
    p -> u = 0;
    for (int i = 0; i < 26; ++i){
        p -> c[i] = NULL;
    }
    return p;
}

void add (int n){
    node *p = &root;
    for (int i = 0; i  < n; ++i){
        int c = (int) s[i] - 'a';
        if  (p -> c[c] == NULL) p-> c[c] = make(p -> c[c]);
        p = p -> c[c];
    }
    p -> u += 1;
}

void start(){
    int m;
    cin >> m;
    cin.getline(s, N);
    for (int i = 1; i <= m; ++i){
        cin.getline(s, N);
        add (strlen (s));
    }
}

int dfs (node*p){
    int f = 0;
    for (int i = 0; i < 26; ++i){
        if (p->c[i] == NULL) continue;
        f = max (f, dfs (p -> c[i]));
    }
    f += p-> u;
    return f;
}

int main()
{
    make (&root);
    start();
    cout << dfs (&root);
    return 0;
}
