#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "AVERAGE" + (string)".INP";
    const string FileOUT = "AVERAGE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e6 + 1;
long long a[N], n, p, ans = 0;

int main ()
{
    Init();
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", &a[i]);
        a[i] += a[i - 1];
    }
    scanf ("%d", &p);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
           ans += (a[j] - a[i - 1] >= p * (j - i + 1));
        }
    }
    printf ("%d", ans);
    return 0;
}