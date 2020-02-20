#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
int b[N], n, t = 1;
pair <int, int> a[N];
bool ok [N];

int main(){
    freopen("RACE.INP", "r", stdin);
    freopen("RACE.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        int ans = a[t].second;
        for (int j = 1; j <= n; ++j){
            if (a[j].first > b[i] && !ok[j]) {
                ans = a[j].second;
                ok[j] = true;
                break;
            }
        }
        if (ans == a[t].second) {
                ok[t] = true;
                t++;
        }
        cout << ans << ' ' << i << endl;
    }
    return 0;
}
