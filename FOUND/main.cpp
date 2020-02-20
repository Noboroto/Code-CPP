#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5;
int a[N], n, m;

void start (){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
}

bool bs (int x){
    int l = 1, r = n, g;
    while (l <= r){
        g = (l + r) / 2;
        if (a[g] == x) return true;
        if (a[g] < x) l = g + 1;
        if (a[g] > x) r = g - 1;
    }
    return false;
}

int main(){
    freopen("FOUND.INP", "r", stdin);
    freopen("FOUND.OUT", "w", stdout);
    start();
    for (int i = 1; i <= m; ++i){
        int x;
        cin >> x;
        if (bs (x)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}
