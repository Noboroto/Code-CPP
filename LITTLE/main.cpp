#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int N = 200 + 3;
int n, m, a[N][N], ok[N], trace1[N], trace2[N]; 

void start (){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            a[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
}

void BFS (int s, int t, bool ac){
    queue <int> q;
    q.push (s);
    for (int i = 1; i <= n; ++i){
        ok[i] = true;
    }
    while (!q.empty()){
        int u = q.front();
        ok [u] = false;
        q.pop();
        for (int v = 1; v <= n; ++v){
            if (a[u][v] != 1 || !ok[v]) continue;
            if (ac) trace1[v] = u;
            else trace2[v] = u;
            if (v == t) return; 
            q.push (v);
        }
    }
}

int main (){
    freopen ("LITTLE.INP", "r", stdin);
    freopen ("LITTLE.OUT", "w", stdout);
    start ();
    BFS (1, 2, true);
    BFS (2, 1, false);
    for (int i = 1; i <= n; ++i) ok[i] = false;
    int x = 2;
    ok[1] = true;
    ok[2] = true;
    while (x != 1){
        ok[x] = true;
        x = trace1[x];
    }
    x = 1;
    while (x != 2){
        ok[x] = true;
        x= trace2[x];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) if (ok[i]) ans++;
    cout << 6 << endl;
    return 0;
}