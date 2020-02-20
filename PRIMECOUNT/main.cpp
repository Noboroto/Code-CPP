#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6;
int a[N], b[N], n, m;

int main (){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    int ans = 0;
    sort (a + 1, a + 1 + n);
    sort (b + 1, b + 1 + m);
    for (int i = 1;  i <= m; ++i){
        int x = b[i];
        for (int j = 1; j <= n; ++j){
            int y = a[j];
            if (x < y) {
                a[j] = 0;
                b[i] = 0;
                ans++;
                break;
            }
        }
        if (x >= b[n]) break;
    }
    cout << ans;
    return 0;
}
