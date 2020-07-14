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
int n, a[N], f[N], q;

void Prepare ()
{
    for (int i = 2; i < N; ++i)
    {
        a[i] = (a[i] != 0) ? a[i] : i - 1;
        if (i * i > N) break;
        for (int j = i; j*i < N; j++)
        {
            a[j*i] = j;
        }
    }
    f[1] = 1;
    for (int i = 2; i < N; ++i)
    {
        f[i] = min (f[i - 1], f[a[i]]) + 1;
    }
}

int GetResult (int n)
{
    if (n >= 0) return f[n];
    else 
    {
        
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
        printf ("%d\n", GetResult (x));
    }
    return 0;
}