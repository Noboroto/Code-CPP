#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
    int x, y;
    point (int _x = 0,int _y = 0){
        x = _x;
        y = _y;
    }
    bool operator < (const point b){
        if (x < b.x) return true;
        if (x == b.x && y < b.y) return true;
        return false;
    }
};

const int N = 1e5 + 10;
point a[N];
int n;
bool ok[N];

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].x;
        a[i].y = i;
        ok[i] = true;
    }
}

void solve (){
    int ans = 0;
    sort (a + 1, a + 1 + n);
    for (int j = 1; j <= n; ++j){
        int i = a[j].y;
        if (!ok[i]) continue;
        ok[i] = false;
        ok[i - 1] = false;
        ok[i + 1] = false;
        ans++;
    }
    cout << ans;
}

int main (){
    start();
    solve();
    return 0;
}
