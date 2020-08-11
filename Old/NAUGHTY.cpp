#include <cstdio>

using namespace std;

const int N = 1e5 + 7;
int a[N], n, k;

void start (){
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
    }
}

void solve (){
    for (int i = 1; i <= n; ++i){
        int s = 0;
        for (int j = i; j > 0; --j)
            if (a[j] <= a[i] + k) s++;
            else break;
        for (int j = i + 1; j <= n; ++j)
            if (a[j] <= a[i] + k) s++;
            else break;
        printf("%d ", s);
    }
}

int main(){
    freopen("NAUGHTY.INP", "r", stdin);
    freopen("NAUGHTY.OUT", "w", stdout);
    start();
    solve();
    return 0;
}
