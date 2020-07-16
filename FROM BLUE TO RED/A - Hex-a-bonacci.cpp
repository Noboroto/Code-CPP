#include <bits/stdc++.h>

using namespace std;

const int oo = 10000007;
int const N = 1e4 + 1;
int a, b, c, d, e, f, n, t;
long long Fibo[N];

long long GetResult (int &a, int &b, int &c, int &d, int &e, int &f, int &n)
{
    Fibo[0] = a % oo;
    Fibo[1] = b % oo;
    Fibo[2] = c % oo;
    Fibo[3] = d % oo;
    Fibo[4] = e % oo;
    Fibo[5] = f % oo;
    for (int i = 6; i <= n; ++i)
    {
        Fibo[i] = (Fibo[i - 1] + Fibo[i - 2] + Fibo[i - 3] + Fibo[i - 4] + Fibo[i - 5] + Fibo[i - 6]) % oo;
    }
    return Fibo[n] % oo;
}

int main ()
{
    scanf ("%d", &t);
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %lld\n", i, GetResult (a,b,c,d,e,f,n));
    }
    return 0;
}