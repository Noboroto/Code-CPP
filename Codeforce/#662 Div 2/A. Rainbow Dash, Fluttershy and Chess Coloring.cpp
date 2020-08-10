#include <bits/stdc++.h>

using namespace std;

int t, n;

int main ()
{
    scanf ("%d", &t);
    while (t > 0)
    {
        scanf ("%d", &n);
        printf("%d\n", n / 2 + 1);
        t--;
    }
    return 0;
}