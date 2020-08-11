#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
const int N = 1e4 + 7;
bool check [N];

int main () {
    ll n, maximum = 0;
    cin >> n;
    for (int i = 0; i < n; ++ i) {
        ll x, t;
        cin >> x;
        maximum = max (t, x);
        t = sqrt(x);
        if (t*t == x) {
            check[t] = true;
           
        }
    }
    for (int i = 0; i <= maximum; ++i){
        if (!check[i]) {
            cout << i*i;
            break;
        }
    }
    return 0;
}