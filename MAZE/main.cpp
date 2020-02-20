#include <cstdio>

using namespace std;

const int N = 1e3;
const int dx[]={-1,0,1,0};
const int dy[]={0,1,0,-1};
char c[N][N];
bool vis[N][N];
int n, m, k, s;

void DFS(int x,int y){
    vis[x][y]=true;
    for (int i = 0; i < 4; ++i) {
        int u,v;
        u = x + dx[i];
        v = y + dy[i];
        if (u >= 0 && u < n &&v >= 0 && v < m && c[u][v]== '.' && !vis[u][v])
            DFS(u, v);
    }
    if (s < k){
        c[x][y]='X';
        s++;
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i) scanf("%s",c[i]);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (c[i][j] == '.') {
                DFS(i,j);
                for (int t = 0; t < n; ++t)
                    printf("%s\n",c[t]);
                return 0;
            }
        }
    }
    return 0;
}
