#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

void Init ()
{
    freopen ("data.INP", "r", stdin);
    freopen ("data.OUT", "w", stdout);
}

const int N = 1e4 + 1;
int n, x, a[N], k;
long long ans = 0;
bool Checked[N];

int main ()
{
    Init();
    scanf ("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%d", &a[i]);
    }
    sort (a, a + n);
    for (int i = 0; i < n; ++i)
    {
        if (Checked[i]) continue;
        Checked[i] = true;
        k = upper_bound (a, a + n, x - a[i]) - a - 1;
        while (k >= 0 && Checked[k]) k--;
        Checked[k] = true;
        ans++;
    }
    printf ("%lld", ans);
    return 0;
}