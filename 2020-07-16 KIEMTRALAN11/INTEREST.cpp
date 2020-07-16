#include <bits/stdc++.h>

using namespace std;

void Init()
{
    const string FileINP = "INTEREST" + (string) ".INP";
    const string FileOUT = "INTEREST" + (string) ".OUT";
    freopen(FileINP.c_str(), "r", stdin);
    freopen(FileOUT.c_str(), "w", stdout);
}

const int N = 1e5 + 1;
long long n, s, a[N];

int main()
{
    Init();
    scanf("%lld%lld", &n, &s);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    for (long long i = 1; i <= n; ++i)
    {
        long long ans = 0;
        for (long long j = i + 1; j <= n && a[j] - a[i - 1] <= 2 * s; j += 2)
        {
            if (a[j] - a[j - j / 2] <= s && a[j - j / 2] - a[i - 1] <= s)
                ans = max (ans, j - i + 1);
        }
        printf ("%lld\n", ans);
    }
    return 0;
}