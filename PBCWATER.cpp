#include <iostream>
#include <cstdio>

using namespace std;

const int dx [4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int N = 1000 + 2;
int a[N][N], n, m;
bool ok[N][N];

struct DISJOINT_SET {
    int sum[N], root[N], mi [N];
    DISJOINT_SET (int m = 0, int n = 0){
        root[0] = -2*m - 2*n;
        mi [0] = 0;
        for (int i = 1; i < m + 1; ++i){
            for (int j = 1; j < n + 1; ++j){
                int x = (i - 1)*n + j;
                root[x] = -1;
                sum[x] = a[i][j];
            }
        }
    }
    int GetRoot (int x, int y){
        int v = 0;
        if (x > 0 && y > 0) v = (x - 1)*n + y;
        if (x > m || y > n) v = 0;
        while (root[v] >= 0) v = root[v];
        return v;
    }
    void Combine (int x1, int y1, int x2, int y2){
        int r1 = GetRoot (x1, y1);
        int r2 = GetRoot (x2, y2);
        if (r1 == r2) return;
        int s = root[r1] + root[r2];
        int sj = sum[r1] + sum[r2];
        if (root[r1] > root[r2]){
            root[r1] = r2;
            root[r2] = s;

        } else {
            root[r1] = s;
            root[r2] = r1;
        }
        sum[r2] = sj;
        sum[r1] = sj;
    }
};

DISJOINT_SET set;

void start (){
    cin >> m >> n;
    for (int i = 0; i < max (n, m) + 1; i++){
        ok[i][0] = true;
        ok[0][i] = true;
        a[i][0] = 0;
        a[0][i] = 0;
    }
    for (int i = 0; i <= n + 1; ++i) {
        ok[m + 1][i] = true;
        a [m + 1][i] = 0;
    }
    for (int i = 0; i <= m + 1; ++i) {
        ok[i][n + 1] = true;
        a [i][n + 1] = 0;
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            ok[i][j] = true;
        }
    }
    set = DISJOINT_SET (m, n);
}
 
void DFS_First (int x, int y, int t){
    ok[x][y] = false;
    for (int i = 0; i < 4; ++i){
        int u = x + dx[i];
        int v = y + dy[i];
        if (u < 0 || v < 0 || u > m + 1 || v > n + 1) continue;
        if (!ok[u][v] || a[u][v] < t) continue;
        set.Combine(x,y,u,v);
        DFS_First (u, v, a[u][v]);
    }
}

int DFS_Second (int x, int y, int ans){
    ok[x][y] = false;
    for (int i = 0; i < 4; ++i){
        int u = x + dx[i];
        int v = y + dy[i];
        if (u < 0 || v < 0 || u > m + 1 || v > n + 1) continue;
        int r1 = set.GetRoot (u, v), r2 = set.GetRoot (x, y);
        if (!ok[u][v] && r1 != r2) 
            ans = min (ans, a[u][v]);
        if (r1 == r2 || !ok[u][v]) continue;
        set.Combine (x, y, u, v);
        ans = min (ans, DFS_Second (u, v, ans));
    }
    return ans;
}

int main (){
    freopen ("WATER.INP", "r", stdin);
    freopen ("WATER.OUT", "w", stdout);
    start ();
    DFS_First (0, 0, 0);
    int ans = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (!ok[i][j]) continue;
            int tmp = DFS_Second(i, j, (1e9) + 7);
            int r = set.GetRoot (i, j);
            set.mi[r] = tmp;
        }
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            int r = set.GetRoot (i, j);
            ans += max (0, set.mi[r] - a[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}