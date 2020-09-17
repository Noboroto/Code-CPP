#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("eratosthene.INP", "r", stdin);
    freopen ("eratosthene.OUT", "w", stdout);
}

const long long N = 5e6 + 1;
vector<bool> isPrime(N, true);
long long l, r;

int main ()
{
    Init();
    cin >> l >> r;
    for (long long i = 2; i * i <= r; ++i) 
    {
        for (long long j = max(i * i, (l + i - 1) / i * i); j <= r; j += i) {
            isPrime[j - l] = false;
        }
    }
    if (1 >= l) 
    { 
        isPrime[1 - l] = false;
    }
    long long sum = 0;
    for (long long x = l; x <= r; ++x) {
        if (isPrime[x - l]) {
            sum++;
        }
    }
    cout << sum;
    return 0;
}