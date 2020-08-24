/*
https://codeforces.com/contest/1373/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

long long t, a, b, c;

void Solve (long long &a, long long &b, long long &c)
{
    if (a < c)
    {
        printf ("1");
    }
    else printf ("-1");
    printf (" ");
    if (a * b > c)
    {
        printf ("%lld", b);
    }
    else printf ("-1");
    printf ("\n");
}

int main ()
{
    scanf ("%d", &t);
    for (long long i = 0; i < t; ++i)
    {
        scanf ("%d %d %d", &a, &b, &c);
        Solve (a, b, c);
    }
    return 0;
}