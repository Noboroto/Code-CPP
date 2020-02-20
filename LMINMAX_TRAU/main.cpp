#include <iostream>

using namespace std;

const int N = 9e4 + 7;
int a[N], n, k;

void start (){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

int main(){
    //freopen("LMINMAX.INP", "r", stdin);
    //freopen("LMINMAX.OUT", "w", stdout);
    int ans = 0;
    start();
    for (int i = 1; i <= n; ++i){
        int ma = a[i], mi = a[i], s = 0;
        for (int j = i + 1; j <= n; ++ j){
            ma = max (ma, a[j]);
            mi = min (mi, a[j]);
            if (ma - mi <= k) s = j - i + 1;
        }
        ans = max (ans, s);
    }
    cout << ans;
    return 0;
}
