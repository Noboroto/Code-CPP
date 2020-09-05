#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("matrix.INP", "r", stdin);
    freopen ("matrix.OUT", "w", stdout);
}

const int N = 1e6 + 1;
const long long oo = 1e9 + 7;
long long m, n, i;
long long ans = 1;
long long GiaiThua[N];

void Prepare ()
{
    GiaiThua[0] = 1;
    for (i = 1; i < N; ++i) GiaiThua[i] = (GiaiThua[i - 1] * i) % oo;
}

long long Pow (long long a, long long n)
{
    if (n == 0) return 1;
    if (n == 1) return a % oo;
    long long t = Pow (a, n / 2) % oo;
    if (n % 2 == 0) return (t * t) % oo;
    else return ((t * t) % oo * (a % oo)) % oo;
}

int main ()
{
    Init();
    cin >> m >> n;
    if (m > n) swap(n, m);
    Prepare();
    ans = Pow (GiaiThua[m], (n - m + 1)) % oo;
    for (i = 2; i < m; ++i)
    {
        ans = (ans * (Pow (GiaiThua[i], 2) % oo)) % oo;
    }
    cout << ans;
    return 0;
}