#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int N = 800;
bool a[N][N], done[N][1], ;
int n;

void start(){
    int m, u, v;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++i){
            a[i][j] = false;
        }
    }
    for (int i = 1; i <= m; ++i){
        cin >> u >> v;
        a[u][v] = true;
    }
}

int main()
{
    return 0;
}
