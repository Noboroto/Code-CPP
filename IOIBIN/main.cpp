#include <iostream>

using namespace std;

struct DISJOINT_SET{
    int root[10000 + 1];
    int GetRoot (int v){
        while (root[v] != v) v = root[v];
        return v;
    }
    DISJOINT_SET () {for (int i = 0; i <= 10000 + 1; ++i) root[i] = i;}
    void Combine (int r1, int r2){
        root[r2] = r1; 
    }
};

int main (){
    DISJOINT_SET set;
    int p;
    cin >> p;
    for (int i = 1; i <= p; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        int r1 = set.GetRoot (x), r2 = set.GetRoot (y);
        if (z == 1) set.Combine (r1, r2);
        if (z == 2){
            if (r1 == r2) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}