#include <iostream>
#include <cstdio>

using namespace std;

const int N = 5e5 + 7;

int dem [N], a[N], n, ma;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dem[a[i]]++;
        ma = max (ma, dem[a[i]]);
    }
}

void solve (){
    for (int i = 1; i <= n; ++i){
        if (n % i != 0) continue;
        cout << i << ' ';
        if (n / i >= ma) cout << 1 << endl;
        else cout << n/i - ma << endl;
    }
}

int main(){
    start();
    solve();
    return 0;
}
