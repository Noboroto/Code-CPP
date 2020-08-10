#include <iostream>

using namespace std;

const int N = 30000 + 7;
int a[N], b[N], n;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
}

void solve (){
    int result = 0;
    for (int x: a) {
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        b[k] = x;
        result = max(result, k);
}
    cout << result;
}

int main(){
    start();
    solve();
    return 0;
}
