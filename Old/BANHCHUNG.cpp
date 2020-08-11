#include <iostream>

using namespace std;

const int N = 50007;
int n, m, a[N];

void start (){
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        cin >> a[i];
    }
}

int solve (int i, int s){
    if (i > m) return s;
    int x = 0;
    if (s + a[i] <= n) x = solve(i + 1, s + a[i]);
    if (x < n) x = max (x, solve(i + 1, s));
    return x;
}

int main(){
    start();
    int ans = solve(1, 0);
    cout << ans;
    return 0;
}
