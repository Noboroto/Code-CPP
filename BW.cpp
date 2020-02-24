#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 1;

int a[maxn], b[maxn];

int start (int& n) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = i; i <= n; ++i) cin >> b[i];
    sort (a + 1, a + n + 1);
    sort (b + 1, b + n + 1);
    return 0;
}

int solve (int n)
{
    int l = a[1], r = b[1], maxa = 1;
    if (l > r)  swap(l, r);
    for (int i = 1; i <= n; ++i){
        if (a[i] <= l || a[i] >= r||b[i] <= l || b[i] >= r) continue;
        l = a[i];
        r = b[i];
        if (l > r) swap(l,r);
        maxa++;
    }
    cout << maxa;
    return 0;
}
int main()
{
    int n;
    freopen("BW", "r", stdin);
    freopen("BW", "w", stdout);
    start(n);
    solve(n);
    return 0;
}
