#include <iostream>
#include <cstdio>
#include <cmath>

typedef long long ll;
using namespace std;

const int N = 1e7 + 7, am = 3*3*3*3*3*3*3*3;
int a[N], t, l[N], r[N];
bool isPrime [10000007];

void inint (ll l, ll r){
    for (int i = 1; i < N; ++i) isPrime [i] = true;
    for (long long i = 2; i * i <= r; ++i) {
        for (long long j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
            isPrime[j - l] = false;
        }
    }
}

void start (){
    inint(1, 1000000);
    cin >> t;
}

int main(){
    //freopen("DMT.INP", "r", stdin);
    //freopen("DMT.OUT", "w", stdout);
    start();
    for (int i = 1; i <= t; ++i){
        ll l, r;
        cin >> l >> r;
        double x = l/9;
        double y = r/9;
        int s = 0;
        for (; x <= y; ++x){
            if (isPrime[x - 1] && x != 3) s++;
            if (x == am) s++;
        }
        cout << s << endl;
    }
    return 0;
}
