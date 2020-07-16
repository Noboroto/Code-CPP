#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;
int n, t, ans = 0;
int f[N];

void Init ()
{
    const string FileINP = "DEFENSE" + (string)".INP";
    const string FileOUT = "DEFENSE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int main()
{
    Init();
    scanf("%d", &t);
    while (t > 0)
    {
        t--;
        scanf("%d", &n);
        f[0] = -1e9 - 1;
        ans = 1;
        for (int i = 0; i < n; ++i) {
            int x, k;
            scanf("%d", &x);
            k = lower_bound(f ,f + ans, x) - f;
            if (k >= ans) 
            {
                f[ans] = x;
                ans++;
            }
            else f[k] = x;
        }
        printf ("%d\n", ans - 1);
    }
    return 0;
}
