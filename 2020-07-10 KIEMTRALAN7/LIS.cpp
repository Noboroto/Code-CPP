#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LIS" + (string)".INP";
    const string FileOUT = "LIS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e6 + 1;
int a[N], n;
long long ans = 1e18 + 7;

int main ()
{
    Init();
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &a[i]);
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            ans = min (ans, (long long)(a[j] - a[i - 1]));
        }
    }
    printf("%lld", ans);
    return 0;
}