#include <iostream>
#include <cstdio>

using namespace std;

struct point {
    int x, y;
    point (int _x = 0, int _y = 0){
        x = _x;
        y = _y;
    }
    bool operator == (point b){
        if (x != b.x) return false;
        if (y != b.y) return false;
        return true;
    }
};

const int N = 1007, oo = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1,  0,-1};
int n, m, a[N][N], d[N][N], nHeap, pos[N][N];
point heap[4*N];
bool ok[N][N];

void start (){
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
}

void standby (){
    for (int i = 0; i <= m + 1; ++i){
        for (int j = 0; j <= n; ++j){
            d[i][j] = oo;
            pos[i][j] = 0;
            ok[i][j] = true;
            if (i < 1|| i > m) ok[i][j] = false;
            if (j < 1) ok[i][j] = false;
        }
    }
    nHeap = 1;
    a[0][0] = -oo;
    heap[1] = point (0,0);
}

void upHeap (int i, int j){
    int child = pos[i][j];
    if (child == 0) {
        nHeap++;
        child = nHeap;
    }
    int parent = child / 2;
    while (parent > 0 && d[heap[parent].x][heap[parent].y] > d[i][j]){
        heap[child] = heap[parent];
        pos[heap[child].x][heap[child].y] = child;
        child = parent;
        parent = child / 2;
    }
    heap[child] = point (i, j);
    pos[i][j] = child;
}

point downHeap (){
    point ans = heap[1];
    point v = heap[nHeap];
    heap[nHeap] = point (0, 0);
    nHeap--;
    int r = 1;
    while (r * 2 <= nHeap){
        int c = r * 2;
        if (c < nHeap && d[heap[c+1].x][heap[c+1].y] < d[heap[c].x][heap[c].y]) c++;
        if (d[v.x][v.y] <= d[heap[c].x][heap[c].y]) break;
        heap[r] = heap[c];
        pos[heap[r].x][heap[r].y] = r;
        r = c;
    }
    heap[r] = v;
    pos[v.x][v.y] = r;
    return ans;
}

void dijsktra (){
    while (nHeap > 0){
        point u = downHeap();
        if (u.x == m + 1)
        ok[u.x][u.y] = false;
        if (u == point (0,0)){
            for (int i = 1; i <= m; ++i){
                d[i][1] = 1;
                upHeap(i, 1);
            }
            continue;
        }
        if (u.y == n) {
            d[m + 1][n + 1] = d[u.x][u.y];
            upHeap(m + 1, n + 1);
            break;
        }
        for (int i = 0; i < 4; ++i){
            int ax = u.x + dx[i];
            int ay = u.y + dy[i];
            int c = (a[u.x][u.y] != a[ax][ay]);
            if (!ok[ax][ay] || d[ax][ay] <= (d[u.x][u.y] + c)) continue;
            d[ax][ay] = d[u.x][u.y] + c;
            upHeap(ax, ay);
        }
    }
    cout << d[m + 1][n + 1];
}

int main(){
    freopen("FAIR.INP", "r", stdin);
    freopen("FAIR.OUT", "w", stdout);
    start();
    standby();
    dijsktra();
    return 0;
}
