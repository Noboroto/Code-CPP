#include <cstdio>

using namespace std;

int n, k, x, ans = 0, mod;

void Reverse (int sum, int i, int n, int mode)
{
    if (i >= n)
    {
        if (mode == 1 && sum == 0) ans++;
        else if (mode == 2 && (sum + mod) % 3 == 0) ans++;
        return;
    }
    for (int t = 0; t < 10; t++)
    {
        if (mode == 2 && i == 0 && t == 0) continue;
        if (t == x) continue;
        Reverse ((sum + t) % 3, i + 1, n, mode);
    }
}

int main ()
{
    scanf ("%d%d%d", &n, &k, &x);
    mod = (k % 3 * x % 3) % 3;
    Reverse (mod, 0, n - k, 1);
    Reverse (0, 0, n - k, 2);
    printf ("%d", ans);
    return 0;
}