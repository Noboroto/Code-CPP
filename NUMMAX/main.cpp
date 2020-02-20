#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

struct p {
    int u, v;
    p (int _u = 0, int _v = 0){
        u = _u;
        v = _v;
    }
};


const int N = 1e5 + 1;
int n, b, a[N];
vector <int> pos;
vector <p> ans;

void start (){
    cin >> n >> b;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] == b) pos.push_back(i);
    }
}

void solve (){
    for (int i = 0; i < pos.size(); ++i){
        int t = pos[i];
        int u = t - 1, v = t + 1;
        while (a[u] < b && u > 1) u--;
        while (a[v] < b && v < n) v++;
        ans.push_back(p(u,v));

    }
    int answer = 1;
    cout << answer << endl;
}

int main(){
    freopen("NUMMAX.INP", "r", stdin);
    freopen("NUMMAX.OUT", "w", stdout);
    start();
    solve();
    return 0;
}
