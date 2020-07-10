#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "EXPRESS" + (string)".INP";
    const string FileOUT = "EXPRESS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1000 + 1;
int n;
long long a[N];
long long ans = 0;

long long GetData ()
{
    long long sum = 0;
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d",&a[i]);
        sum += a[i];
    }
    return sum;
}

void Reverse (long long sum, int t, int j)
{
    if (t == 2)
    {
        ans = max (sum, ans);
        return;
    }
    for (int i = j; i < n; ++i)
    {
        Reverse (sum - a[i] - a[i - 1] + a[i] * a[i -1], t + 1, i + 2);
        if (t == 0 && i > 1) Reverse (sum - a[i] - a[i - 1] - a[i - 2] + a[i]*a[i-1]*a[i - 2], 2, i + 3);
    }
}

int main ()
{
    Init();
    Reverse (GetData(), 0, 1);
    printf ("%lld", ans);
    return 0;
}