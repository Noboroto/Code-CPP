#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;
int n, k, m;
struct Edge
{
    int from, to, price;
    Edge (int _from, int _to, int _price){
        from =_from;
        to = _to;
        price = _price;
    }
    bool operator < (const Edge b){
        if (price < b.price) return true;
        if (price >= b.price && from < b.from) return true;
        if (price >= b.price && from >= b.from && to < b.to) return true;
        return false;
    }
    bool operator > (const Edge b){
        if (price > b.price) return true;
        if (price <= b.price && from > b.from) return true;
        if (price <= b.price && from <= b.from && to > b.to) return true;
        return false;
    }
};
const int N = 100;
root[N];

int Find_Root (int v){
    while (root[v] > 0)
    {
        v = root[v];
    }
    return v;
}

void Merge (int u, int v){
    u = Find_Root(u);
    v = Find_Root(v);
    if (root[u] > root[v]{
        root[u] = v;
        root[v]--;
    }
    else
    {
        root[v] = u;
        root[v]--;
    }
}

int main () {
    freopen ("CITIES.INP", "r", stdin);
    freopen ("CITIES.OUT", "w", stdout);
    cin >> n >> k >> m;    
    int xy;
    for (int i = 0; i < k; ++i){
        cin >> xy;
    }
    for (int i = 0; i < m; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        
    }
    return 0;
}