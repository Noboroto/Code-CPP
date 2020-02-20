#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1000;
const int Dx[8] = { 1, 0,-1, 0, 1,-1, 1,-1};
const int Dy[8] = { 0, 1, 0,-1,-1,-1, 1, 1};
int Heigh [N][N];
bool Free [N][N];
struct Node {
    int x, y, val = 0;
    Node (int _x = 0, int _y = 0){
        x = _x;
        y = _y;
        val = max (Heigh[x][y], 0);
    }
};

bool Compare (const Node &a, const Node &b){
    return (a.val > b.val);
}
int m, n, ans = 0;

int BFS (Node u){
    if (u.x < 1 || u.y < 1 || u.x > n || u.y > m) return 0;
    bool isHigh = true;
    Node v;
    queue <Node> Queue;
    Queue.push(u);
    while (!Queue.empty()){
        u = Queue.front();
        Queue.pop();
        Free[u.x][u.y] = false;
        for (int i = 0; i < 8; ++i){
            v = Node (u.x + Dx[i], u.y + Dy [i]);
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
            if (u.val < v.val){
                isHigh = false;
                continue;
            }
            if (!Free[v.x][v.y] || u.val != v.val) continue;
            Queue.push(v);
        }
    }
    if (isHigh) return 1;
    else return 0;
}

int main (){
    ios_base::sync_with_stdio(false);
    memset (&Free, true, sizeof (Free));
    memset (&Heigh, 0, sizeof (Heigh));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <=m; ++j){
            cin >> Heigh[i][j];
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <=m; ++j){
            if (Free[i][j]) ans += BFS (Node (i, j));
        }
    }
    cout << ans;
    return 0;
}