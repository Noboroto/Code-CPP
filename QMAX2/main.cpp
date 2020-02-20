#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int start();

vector <int> a;
int q, m;

int main (){
    freopen("QMAX2.INP", "r", stdin);
    freopen("QMAX2.OUT", "w", stdout);
    start();
    for (int i = 1; i < a.size(); ++i)
            cout << a[i] << ' ';
    return 0;
}

int start (){
    int c, n;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> c;
        a.push_back(c);
    }
    return 0;
}
