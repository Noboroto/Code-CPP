#include <iostream>
#include <cstdio>

using namespace std;

int a, b, c, s;

void solve (){
    int t = 0;
    cin >> a >> b >> c;
    if (a + b > c) {
        cout << 0 << endl;
        return;
    }
    if (a + b == c){
        cout << 1 << endl;
        return;
    }
    for (int x = 1; x <= c/a; ++x){
        for (int y = 1; y <= c/b; ++y){
            if (a*x + b*y == c) t++;
        }
    }
    cout << t << endl;
}

int main(){
    freopen("DIOPHANTINE.INP", "r", stdin);
    freopen("DIOPHANTINE.OUT", "w", stdout);
    cin >> s;
    for (int i = 1; i <= s; ++i){
        solve();
    }
    return 0;
}
