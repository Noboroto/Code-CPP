#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 1000, M = 50, L = 1e5, R = 1e8;
typedef long long matrix [N][N];
typedef long long mat [1][N];
matrix a, b, c;
mat d, tmp1, tmp2;
int n, t;
bool ans;

void mul (matrix a, matrix b){
    for (int i = 0; i< 1; ++i){
        for (int j = 0; j < n; ++j){
            tmp2[i][j] = 0;
            for (int k = 0; k < n; ++k){
                tmp2[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void pick () {
    for (int j = 0; j < n; ++j){
        srand(time(NULL));
        d[0][j] = rand() % R + L;
    }
}

void copya (mat tmp){
    for (int j = 0; j < n; ++j){
        tmp1[0][j] = tmp [0][j];
    }
}

bool same (mat a, mat b){
    for (int i = 0; i < 1; ++i){
        for (int j = 0; j < 1; ++j){
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

int main (){
    scanf("%d", &t);
    for (int z = 1; z <= t; ++z){
        scanf("%d",&n);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                int k;
                scanf("%d", &k);
                a[i][j] = k;
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                int k;
                scanf("%d", &k);
                b[i][j] = k;
            }
        }
        for (int i = 0; i < n; ++i){
            for (int j = 0; j< n; ++j){
                int k;
                scanf("%d", &k);
                c[i][j] = k;
            }
        }
        ans = true;
        for (int i = 1; i < M; ++i){
            pick();
            mul(d, a);
            copya(tmp2);
            mul (tmp1, b);
            copya (tmp2);
            mul (d, c);
            if (!same(tmp2, tmp1)) {
                    ans = false;
                    break;
            }
        }
        if (ans) printf ("YES");
        else printf("NO");
        prinf("\n");
    }
    return 0;
}
