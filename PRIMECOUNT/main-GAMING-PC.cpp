#include <iostream>
#include <cstdio>

typedef long long ll;
using namespace std;

const int N = 1e8 + 9e7;
ll l[1001], r[1001];
bool isPrime [N];

void inint (ll l, ll r){
    for (int i = 0; i < N; ++i) isPrime [i] = true;
    for (long long i = 2; i * i <= r; ++i) {
        for (long long j = max(i * i, (l + (i - 1)) / i * i); j <= r; j += i) {
            isPrime[j - l] = false;
        }
    }
}

int main(){
    freopen("PRIMECOUNT.INP", "r", stdin);
    freopen("PRIMECOUNT.OUT", "w", stdout);
    int  t = 0;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> l[i] >> r[i];
        ll ml;
        if (l[i] < l[i - 1] || r[i] > r[i-1]){
            inint(l[i], r[i]);
            ml = l[i];
        }
        int s = 0;
        for (ll j = max (l[i],(ll)2); j <= r[i]; ++j){
            if (isPrime[j - ml]) s++;
        }
        cout << s << endl;
    }
    return 0;
}
