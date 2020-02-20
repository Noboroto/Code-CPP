#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 1e8 + 1;

bool isPrime [N];
ll mu[N];

void SangNguyenTo (int n){
    for (int i = 2; i <= n;++i)
        {isPrime[i] = true;
        mu[i] = 1;
    }
    for (int i = 2; i <= n;++i) {
        if (isPrime[i]){
            for (int j = i*2; j <= n; j += i){
                isPrime [j] = false;
            }
        }
    }
}

int main()
{
    freopen("COUTDI1.INP", "r", stdin);
    freopen("COUTDI1.OUT", "w", stdout);
    int n;
    cin >> n;
    ll ans = 1;
    SangNguyenTo(n);
    ll tmp = n;
    for (ll j = 2; j <= n; ++j){
        if (isPrime[j]){
            while (tmp > 1 && tmp % j == 0)
            {
                tmp /= j;
                mu[j]++;
            }
        }
        if (tmp == 1) break;
    }
    for (int i = 2; i <= n; ++i) ans *= mu[i];
    cout << ans - 1;
    return 0;
}
