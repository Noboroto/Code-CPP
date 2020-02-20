#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5;
int m, n, a[N][N], b[N][N], ans = 0;
bool ok [N][N];

void start (){
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            int x = 0;
            cin >> x;
            a[i][j] = x;
            b[i][j] = x;
            ok [i][j] = true;
        }
    }
}
int x[10][10];

void found (){
    int d[N][N];
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (!ok[i][j]) continue;
            if (a[i][j] == 0){
                int r = i + 1;
                while (x[r][j] == 0) {
                        a[i][j] = a[i][j] * 10 + a[r][j];
                        ok[r][j] = false;
                        r++;
                }
            }
        }
    }
}
void tryyy(int i,int j)
{
    for (int z=0;z<2;z++)
    {
        x[i][j]=z;
        if (i==n-1 && j==m-1)
        {
            found();
        }
        else
        {
            if (j==m-1) tryyy(i+1,0);
            else tryyy(i,j+1);
        }
    }
}


int main(){
    start();
    tryyy(0,0);
    cout << ans;
    return 0;
}
