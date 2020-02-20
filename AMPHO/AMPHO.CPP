#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main (){
    freopen ("AMPHO.INP", "r", stdin);
    freopen ("AMPHO.OUT", "w", stdout);
    int n, m, x;
    vector <int> a;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> x;
        x = m - x;
        a.push_back(x);
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 0; j < n; ++j){
            if (i <= a[j]) cout << '.';
            else cout << '#';
        }
        cout << endl;
    }
    return 0;
}