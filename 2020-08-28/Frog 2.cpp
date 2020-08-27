/*
https://atcoder.jp/contests/dp/tasks/dp_b
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n, k;
ll h[N], f[N];

void Init ()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) 
    {
        cin >> h[i];
        f[i] = 1e9 + 7;
    }
    f[0] = 0;
}

int main ()
{
    Init();
    for (int i = 1; i < n; ++i)
    {
        for (int j = max (0, i - k); j < i; ++j)
        {
            f[i] = min (f[i], f[j] + abs (h[i] - h[j]));
        }
    }
    cout << f[n - 1];
    return 0;
}