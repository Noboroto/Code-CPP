#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

struct node {
    int u, v;
    node *c [2];
};

const int K = 65536;
const int B = 17;
int s[B], n, k, seed, ad, mul, q;
queue <int> a;
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

void start (){
    cin >> seed >> mul >> ad >> n >> k;
    a.push(seed);
    transbit(seed);
    add(seed);
    long long x = seed;
    for (int i = 1; i < k; ++i){
        x = (x * mul + ad) % K;
        transbit(x);
        add (x);
        a.push(x);
    }
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
    freopen("MEDIAN.INP", "r", stdin);
    freopen("MEDIAN.OUT", "w", stdout);
    cin >> q;
    make (&root);
    for (int i = 1; i <= q; ++i){
        start();
        long long sum = 0;
        sum = solve (&root, 0, (k + 1) / 2);
        for (int j = k; j < n; ++j){
            long long num =a.back();
            transbit(a.front());
            del (&root, 0);
            num = (num * mul + ad) % K;
            transbit(num);
            add(num);
            a.pop();
            a.push(num);
            sum += solve(&root, 0, (k + 1) / 2);
        }
        while (!a.empty()){
            transbit(a.front());
            del(&root, 0);
            a.pop();
        }
        cout << "Case #" << i << ": " << sum << endl;
    }
    return 0;
}
