/*
https://atcoder.jp/contests/dp/tasks/dp_c
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 1;
int n;
ll f[N][3];

void Init ()
{
    cin >> n;
    for (int i = 0; i < n ; ++i)
    {
        cin >> f[i][0] >> f[i][1] >> f[i][2];
    }
}

ll GetResult ()
{
    for (int i = 1; i < n; ++i)
    {
        f[i][0] += max (f[i - 1][1], f[i - 1][2]);
        f[i][1] += max (f[i - 1][0], f[i - 1][2]);
        f[i][2] += max (f[i - 1][0], f[i - 1][1]);
    }
    return max (f[n - 1][0], max (f[n - 1][1], f[n - 1][2]));
}

int main ()
{
    Init();
    cout << GetResult();
    return 0;
}