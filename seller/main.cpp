#include <iostream>

using namespace std;

const int N = 50000;
int a[N], f[N], n, m;

int solve (int l, int r){
    int ans = 0, maxa = 0;
    for (int i = 1; i <= n; ++i) f[i] = 0;
    for (int i = l; i <= r; ++i){
        int v = a[i];
        f[v]++;
        if (f[v] > maxa){
            maxa = f[v];
            ans = v;
        }
    }
    int c = (r - l + 1)/2;
    if (maxa <= c) ans = 0;
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i){
        int l, r;
        cin >> l >> r;
        int ans = solve (l, r);
        cout << ans << endl;
    }
    return 0;
}
