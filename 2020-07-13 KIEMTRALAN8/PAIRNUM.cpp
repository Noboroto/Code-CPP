#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "PAIRNUM" + (string)".INP";
    const string FileOUT = "PAIRNUM" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e5 + 1;
int n;
int a[N];
long long c[N];

void Prepare (int n)
{
    c[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        c[i] = c[i - 1] + i - 1;
    }
}

int main ()
{
    long long ans = 0;
    Init();
    scanf ("%d", &n);
    Prepare(n);
    int x = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", &x);
        a[x]++;
    }
    for (int i = 1; i < N; ++i)
    {
        ans += c[a[i]];
    }
    printf ("%lld", ans);
    return 0;
}