#include <cstdio>

const int N = 1e6 + 1;
int n, H[N], J[N];
int j, i;

int main ()
{
    freopen ("FROGS.INP", "r", stdin);
    freopen ("FROGS.OUT", "w", stdout);
    scanf ("%d", &n);
    for (i = 1; i <= n; ++i)
    {
        scanf ("%d", &H[i]);
    }
    for (i = 1; i <= n; ++i)
    {
        scanf ("%d", &J[i]);
    }
        for (i = 1; i <= n; ++i)
    {
        for (j = i + 1; j <= n && J[i] > 0; ++j)
        {
            if (H[i] < H[j])
            {
                J[i]--;
                H[i] = H[j];
            }
        }
        if (J[i] > 0) H[i] = -1;
    }
    for (i = 1; i <= n; ++i) printf ("%d ", H[i]);
    return 0;
}