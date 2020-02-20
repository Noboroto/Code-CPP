#include <iostream>
#include <cstring>

using namespace std;

struct node {
    int f;
    node *c [26];
};

const int N = 15000;
char s[N], num [26];
node root;
bool ok [26];
int k, n;

node *make (node * p){
    p = new node;
    p -> f = 1;
    for (int i = 0; i < 26; ++i){
        p -> c[i] = NULL;
    }
    return p;
}

void add (int l, int n){
    node *p = &root;
    int a = 0;
    for (int i = l; i < n; ++i){
        int c = (int) s[i] - 'a';
        if (!ok[c] && a <= k) a++;
        if (a > k) return;
        if (p -> c[c] == NULL) p -> c[c] = make(p -> c[c]);
        p = p -> c[c];
    }
}

void process (){
    for (int i = 0; i < 26; ++i){
        if (num[i] == '1') ok[i] = true;
        else ok[i] = false;
    }
    n = strlen(s);
    for (int i = 0; i < n; ++i){
        add (i, n);
    }
}

void start(){
    cin.getline(s, N);
    cin.getline(num, 27);
    cin >> k;
    process();
}

int dfs (node *p){
    int f = p -> f;
    for (int i = 0; i < 26; ++i){
        if (p -> c[i] == NULL) continue;
        f += dfs(p -> c[i]);
    }
    return f;
}

int main()
{
    make (&root);
    start();
    cout << dfs (&root);
    return 0;
}
