#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

struct vp {
    int x, y, id;
    bool ok;
    bool operator < (vp b){
        if (x < b.x) return true;
        if (x == b.x && y < b.y) return true;
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
    vp (int _x = 0, int _y = 0, int _id = 0, bool o = false){
        x = _x;
        y = _y;
        id = _id;
        ok = o;
    }
};
bool same (vp a, vp b, vp c){
    ll x = (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
    return x >= 0;
}

bool not_same (vp a, vp b, vp c){
    ll x = (b.x - a.x) * (b.y + a.y) + (c.x - b.x) * (c.y + b.y) + (a.x - c.x) * (a.y + c.y);
    return x <= 0;
}
const int N = 1e5;
int n, m;
vp a[N], p1, p2;
bool ans [N];
vector <vp> up, down;

void start(){
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x, y;
        cin >> x >> y;
        a[i] = vp (x,y,i,true);
    }
    sort(a, a + n);
    p1 = a[0];
    p2 = a[n - 1];
    up.push_back(1);
    for (int i = 1; i < n; ++i){

    }
    cin >> m;
    for (int i = n; i < n + m; ++i){
        int x, y;
        cin >> x >> y;
        a[i] = vp (x,y,i - n,false);
    }
    sort (a , a + n + m);
}

void solve (){
    for (int i = 1; i < n + m; ++i){
        if (a[i].ok && same (p1, a[i], p2)) up.push_back(a[i]);
        else if (!same(p1, a[i], p2)){
            ans[a[i].id] = true;
        } else continue;
        if (a[i].ok && not_same (p1, a[i], p2)) down.push_back(a[i]);
        else if (!not_same(p1, a[i], p2)){
            ans[a[i].id] = true;
        }
    }
}

void getout (){
    for (int i = 0; i < m; ++i){
        if (ans[i]) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}

int main(){
    //freopen("METERAIN,INP", "r", stdin);
    //freopen("METERAIN.OUT", "w", stdout);
    start();
    solve();
    getout();
    return 0;
}
