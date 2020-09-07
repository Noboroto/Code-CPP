#include <bits/stdc++.h>

using namespace std;

/*
    https://codeforces.com/group/FLVn1Sc504/contest/274829/problem/E
*/

const int N = 6e3 + 1;
int n, l, i, j;
int a[N], f[N];

void Init ()
{
    scanf ("%d%d", &n, &l);
    for (i = 1; i <= n; ++i)
    {
        scanf ("%d", &a[i]);
        a[i] += a[i - 1];
    }
}

int main ()
{
    Init();
    for (i = 1; i <= n; ++i)
    {
        for (j = i; j > 0; --j)
        {
            f[i] = min (f[i], max (f[j - 1], l - (a[i] - a[j - 1])));
        }
    }
    return 0;
}