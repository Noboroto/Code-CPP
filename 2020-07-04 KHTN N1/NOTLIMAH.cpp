#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9 + 7;
int n, d;

int main ()
{
    cin >> n >> d;
    long long ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans = ((ans % oo) * (i % oo)) % oo;
    }
    cout << ans;
    return 0;
}