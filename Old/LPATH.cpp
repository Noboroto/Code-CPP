#include <iostream>
#include <cstdint>

using namespace std;

struct Node {
    int i, j, c;
    bool operator < (const Node& b){
        return c < b.c;
    }
};
struct node {
    int j, c;
};

const int N = 1e3 + 1;
const int oo = 1e9;
node adj [2*N];
Node a[N];
int head[N];
int n, m, f, l;
Node qu [maxn];

int push(Node i){
    qu [++l] = i;
    return 0;
}

Node pop (){
    return qu [f++];
}

int start(){
    int mina = oo;
    Node g;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].i >> a[i].j >> a[i].c;
        head[a[i].i]++;
        head[a[i].j]++;
        if (a[i].c >)
    }
    sort (a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i){
        adj[head[a[i].i]] = a[i].j;
        adj[head[a[i].j]] = a[i].i;
        adj[head[a[i].i]] = a[i].c;
        adj[head[a[i].j]] = a[i].c;
        head[a[i].i]--;
        head[a[i].j]--;
    }
    return 0;
}

int main(){
    start;
    return 0;
}
