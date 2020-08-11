#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef long double ll;

struct vp {
    ll x, y;
    bool operator < (vp b){
        if (y < b.y) return true;
        if (y == b.y && x < b.x) return true;
        return false;
    }
    bool operator != (vp b){
        if (x != b.x) return true;
        if (y != b.y) return true;
        return false;
    }
    bool operator == (vp b){
        if (x != b.x) return false;
        if (y != b.y) return false;
        return true;
    }
    vp (ll _x = 0, ll _y = 0){
        x = _x;
        y = _y;
    }
};
bool same (vp a, vp b, vp c){
    ll x = (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
    return x > 0;
}

bool not_same (vp a, vp b, vp c){
    ll x = (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
    return x < 0;
}
const int N = 1e6;
int n;
ll s;
vp a[N];
vector <vp> ans;

void start(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> a[i].x >> a[i].y;
    }
    sort (a , a + n);
}

void solve (){
    while (!ans.empty()) ans.pop_back();
    vector <vp> up, down;
    vp p1 = a[0];
    vp p2 = a[n - 1];
    s = 0;
    up.push_back(a[0]);
    down.push_back(a[0]);
    for (int i = 1; i < n; ++i){
        if (i == n - 1 || same (p1, a[i], p2)) {
            while (up.size() >= 2 && !same (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            if (up.back() != a[i]) {
                    up.push_back (a[i]);
            }
        }
        if (i == n - 1 || not_same(p1, a[i], p2)) {
            while (down.size() >= 2 && !not_same(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            if (down.back() != a[i]) {
                    down.push_back (a[i]);
            }
        }
    }
    for (int i = 0; i < (int)up.size(); ++i){
        if (i > 0) s += (up[i].x - ans.back().x) * (up[i].y + ans.back().y);
        ans.push_back(up[i]);
    }
    for (int i = (int)down.size() - 2; i > 0; --i){
        s += (down[i].x - ans.back().x) * (down[i].y + ans.back().y);
        ans.push_back(down[i]);
    }
    s += (ans.front().x - ans.back().x) * (ans.front().y + ans.back().y);
}

int main (){
    freopen("CONVEXHULL.INP", "r", stdin);
    freopen("CONVEXHULL.OUT", "w", stdout);
    start();
    solve();
    cout << ans.size() << endl;
    s = s / 2;
    cout << setprecision(1) << fixed << s << endl;
    cout << setprecision(0) << fixed;
    cout << ans[0].x << ' ' << ans[0].y << endl;
    for (int i = ans.size() - 1; i > 0; --i){
        cout << ans[i].x << ' ' << ans[i].y << endl;;
    }
    return 0;
}
