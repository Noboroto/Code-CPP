#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>

using namespace std;

const int N = 2000 + 1;

bool Edge[N][N];
bool Free[N];
stack <int> Stack;
int Low[N], Num[N], Order, n, m;
long long Component;

void DFS_TPLT (int u){
    Order++;
    Num[u] = Order;
    Low[u] = Order;
    Stack.push (u);
    for (int v = 1; v <= n; v++){
        if (!Edge [u][v] || !Free[v]) continue;
        if (Num [v] != 0) {
            Low [u] = min (Low[u], Num[v]);
        } else {
            DFS_TPLT(v);
            Low[u] = min (Low[u], Low[v]);
        }
    }
    if (Num[u] == Low[u]){
        Component++;
        int v = 0;
        while (v != u){
            v = Stack.top();
            Stack.pop();
            Free[v] = false;
        }
    }
}


int main (){
    //freopen ("ADS.INP", "r", stdin);
    //freopen ("ADS.OUT", "w", stdout);
    cin >> n >> m;
    Order = 0;
    Component = 0;
    memset (&Edge, false, sizeof (Edge));
    memset (&Free, true, sizeof (Free));
    for (int i = 0; i < m; ++i){
        int x, y;
        cin >> x >> y;
        Edge[x][y] = true;
        Edge[y][x] = true;  
    }
    for (int i = 1; i <= n; ++i){
        if (Num[i] == 0) DFS_TPLT(i);
    }
    long long ans = m - n + Component;
    cout << ans << "\n";
    return 0;
}