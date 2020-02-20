#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6;
int a[N], n, m, ans = 0;

void start (){
    cin >> m >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
}

void solve (){
    for (int i = n; i > 0; --i){
        if (m > 0){
            if (m >= a[i]) {
                m -= a[i] - 1;
                a[i] = 1;
            } else {
                a[i] -= m;
                m = 0;
            }
        }
    }
    for (int i = n; i > 0; --i){
        if (m > a[i]) m -= a[i];
        else if (m == 0) ans += a[i]*a[i];
        else {
            ans += (a[i] - m) * (a[i] - m);
            m = 0;
        }
    }
}

int main(){
    start();
    solve();
    cout << ans;
    return 0;
}
