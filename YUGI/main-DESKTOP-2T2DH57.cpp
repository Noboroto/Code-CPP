#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int x, y, c;
    edge (int _x = 0, int _y = 0, int _c = 0){
        x = _x;
        y = _y;
        c = _c;
    }
    bool operator < (const edge b){
        if (c < b.c) return true;
        if (c == b.c && x < b.x) return true;
        if (c == b.c && x == b.x && y < b.y) return true;
        return false;
    }
};

vector <edge> a;
int n, k;
vector <int> root, ans;

void start (){
    root.push_back (0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            int c;
            cin >> c;
            if (j < i) a.push_back (edge (i, j, c));
        }
        root.push_back(-1);
    }
    sort (a.begin(), a.end());
}

int GetRoot (int v){
    while (root[v] > 0) v = root[v];
    return v;
}

void combine (int r1, int r2){
    int sum = root[r1] + root[r2];
    if (r1 > r2){
        root[r1] = r2;
        root[r2] = sum;
    } else {
        root [r2] = r1;
        root [r1] = sum;
    }
}

int Kruskal (){
    int s = 0;
    for (int i = 0; i < a.size(); ++i){
        int r1 = GetRoot (a[i].x);
        int r2 = GetRoot (a[i].y);
        int c = a[i].c;
        if (r1 != r2){
            ans.push_back (c);
            s++;
            combine (r1, r2);
        }
        if (s >= n) break;
    } 
    sort (ans.begin (), ans.end());
    return (ans[s - 2]);
}

int main(){
    //freopen ("YUGI.INP", "r", stdin);
    //freopen ("YUGI.OUT", "w", stdout);
    start ();
    cout << Kruskal ();
    return 0;
}
