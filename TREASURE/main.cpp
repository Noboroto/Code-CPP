#include <iostream>
#include <queue>

using namespace std;

struct node {
    int u, v;
    node (int _u = 0, int _v = 0){
        u = _u;
        v = _v;
    }
    bool operator == (node b){
        if (u != b.u) return false;
        if (v != b.v) return false;
        return true;
    }
    node operator + (node b){
        node c;
        c.u = u + b.u;
        c.v = v + b.v;
        return c;
    }
};

const int N = 1001;
const int dx[4] = {0, 1, 0,-1};
const int dy[4] = {1, 0,-1, 0};

queue <node> q;
int n, m, k = 0;
node s, f, d;
bool ok[N][N];

void start (){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            int x;
            cin >> x;
            if (x == 0){
                q.push(node(i,j));
                d = node(i, j);
            } else k++;
        }
    }
    int u, v;
    cin >> u >> v;
    s = node (u, v);
    cin >> u >> v;
    f = node (u, v);
}

void dfs (){
}

bool solve(int z){
    int t = 0;
    while (!q.empty() && k > 0 && t < z){
        node u = q.front();
        q.pop();
        ok[u.u][u.v] = false;
        for (int i = 0; i < 4; ++i){
            node v = u + node (dx[i], dy[i]);
            if (!ok[v.u][v.v]) continue;
            if (v.u > n || v.v > m || v.u < 1 || v.v < 1) continue;
            k--;
            q.push(v);
        }
        if (u == d){
            t--;
            if (!q.empty()) {
                d = q.back();
            }
        }
    }
    if (!q.empty()) t++;
    if (t <= z) return true;
    else return false;
}

int main(){
    start();
    return 0;
}
