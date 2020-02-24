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


HEAP heap;
DISJOINT_SET set;
int n, m;

void start (){
    int oo = 1e9 + 7;
    heap.UpHeap (edge (oo, oo, oo));
    cin >> n >> m;
    set = DISJOINT_SET (n);
    for (int i = 1; i <= m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        edge a = edge (u, v, c);
        heap.UpHeap(a);
    } 
}

int Kruskal (){
    int ans = 0, s = 0;
    while (s < n - 1){
        edge a = heap.PopHeap();
        int r1 = set.GetRoot(a.u), r2 = set.GetRoot(a.v), c = a.c;
        if (r1 != r2){
            ans += c;
            s++;
            set.Combine (r1, r2);
        }
    }
    return ans;
}

int main (){
    start();
    cout << Kruskal() << endl;
    return 0;
}