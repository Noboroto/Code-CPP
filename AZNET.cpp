#include <iostream>
#include <vector>
 
using namespace std;
 
struct edge{
    int u, v, c;
    edge (int _u = 0, int _v = 0, int _c = 0){
        u = _u;
        v = _v;
        c = _c;
    }
    bool operator < (edge b){
        if (c < b.c) return true;
        if (c == b.c && u < b.u) return true;
        if (c == b.c && u == b.u && v < b.v) return true;
        return false;
    }
};
 
struct HEAP{
    vector <edge> h;
    HEAP (){
        h.push_back (edge());
    }
    void DeBuild (){
        while (!h.empty()) h.pop_back();
        h.push_back(edge());        
    }
    void UpHeap (edge v){
        h.push_back (v);
        int c = h.size() - 1;
        int p = c / 2;
        while (p > 0 && v < h[p]){
            h[c] = h[p];
            c = p;
            p = c/2;
        }
        h[c] = v;
    }   
    edge PopHeap (){
        edge ans = h[1];
        edge v = h.back();
        h.pop_back();
        int r = 1;
        while (r*2 < h.size() - 1){
            int c = r*2;
            if (c < h.size () - 1 && h[c + 1] < h[c]) c++;
            if (v < h[c]) break;
            h[r] = h[c];
            r = c;
        }
        h[r] = v;
        return ans;
    }
};
 

struct DISJOINT_SET{
    vector <int> root;
    int GetRoot (int v){
        while (root[v] > 0) v = root[v];
        return v;
    }
    DISJOINT_SET (int n = 0){
        for (int i = 0; i <= n; ++i)
            root.push_back(-1);
    }
    void Combine (int r1, int r2){
        int sum = root[r1] + root[r2];
        if (r1 > r2){
            root[r1] = r2;
            root[r2] = sum;
        } else {
            root[r2] = r1;
            root[r1] = sum;
        }
    }
};

void solve (vector <int> &ans){
    int n, m;
    cin >> n >> m;
    vector <int> a_val, b_val;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a_val.push_back(x);
    }
    for (int i = 0; i < 0; ++i){
        int x;
        cin >> x;
        b_val.push_back(x);
    }
}

int main (){
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        vector <int> ans;
        solve (ans);
    }
    return 0;
}