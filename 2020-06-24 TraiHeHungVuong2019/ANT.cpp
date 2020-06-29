#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "ANT" + (string)".INP";
    const string FileOUT = "ANT" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n, m;
long long const oo = 1e9 + 7;
vector <long long> Giaithua;

void GetData ()
{
    scanf ("%d %d", &n, &m);
    if (m < m) swap (n, m);
    long long tmp = 1;
    Giaithua.push_back(0);
    for (long long i = 1; i <= m + n; ++i)
    {
        tmp = (tmp % oo * i % oo) % oo;
        Giaithua.push_back (tmp % oo);
    } 
}

long long Pow (long long a, long long n)
{
    if (n == 0) return 1;
    long long t = Pow (a, n / 2) % oo;
    t = (t * t) % oo;
    if (n % 2 == 0) return t;
    else return (t * a % oo) % oo;
}

long long ToHop (long long k, long long n)
{
    if (n == 0 || k == 0 || n == k) return 1;
    if (k == 1) return n;
    long long tu = Giaithua[n] % oo;
    long long mau = Pow (Giaithua[k] % oo * Giaithua[n - k] % oo, oo - 2);
    return ((tu * mau) % oo);
}

int main ()
{
    Init();
    GetData();
    if (m == 0 || n == 0)
    {
        cout << 1;
        return 0;
    }
    long long ans = 0, a, b;
    for (long long i = 0; i <= n; ++i)
    {
        a = (ToHop (i, m + n - i) % oo);
        b = (ToHop (n - i, n + m - 2 * i) % oo);
        ans += (a * b) % oo;
    }
    cout << ans;
    return 0;
}