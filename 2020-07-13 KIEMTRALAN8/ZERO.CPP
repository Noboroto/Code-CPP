#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "ZERO" + (string)".INP";
    const string FileOUT = "ZERO" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 1e6 + 1;
long long a[N];
int n, f[N], q;

void Prepare ()
{
    for (long long i = 2; i < N; ++i)
    {
        a[i] = (a[i] != 0) ? a[i] : i - 1;
        for (long long j = i; j*i < N; j++)
        {
            a[j*i] = min (j, a[j*i]);
        }
    }
    f[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        f[i] = min (f[i - 1], f[a[i]]) + 1;
    }
}

int main ()
{
    Init();
    Prepare ();
    scanf ("%d", &q);
    int x = 0;
    for (int i = 0; i < q; ++i)
    {
        scanf ("%d", &x);
        printf ("%d\n", f[x]);
    }
    return 0;
}