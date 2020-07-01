#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
map <long long, long long> UNN;
bool isPrime[N];
long long n, a[N];

int main ()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 2; i < N; ++i) isPrime[i] = true;
    for (int i = 2; i < N; ++i)
    {
        if (!isPrime[i]) continue;
        UNN[i]++;
        for (int j = 2*i; j < N; j+=i)
        {
            if (!isPrime[j]) continue;
            UNN[i]++;
            isPrime[j] = false;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= N) cout << 0 << '\n';
        else if (isPrime[a[i]]) cout << UNN[a[i]] << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}