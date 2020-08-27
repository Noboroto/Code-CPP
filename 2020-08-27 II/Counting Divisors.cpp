/*
https://cses.fi/problemset/task/1713
*/

#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

ll const N = 1e6 + 1;
int Divisors [N];
ll i, count, ans, j;

void Init ()
{
    memset (Divisors, 0, sizeof (Divisors));
    for (i = 1; i < N; ++i)
    {
        for (j = 1; i*j < N; ++j)
        {
            Divisors[i*j]++;
        }
    }
}

int main ()
{
    Init();
    ll t, x, result;
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> x;
        result = Divisors[x];
        cout << result << ' ';
    }
    return 0;
}