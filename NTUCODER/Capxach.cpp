#include <bits/stdc++.h>

using namespace std;

const int N = 250 + 1;
int n, m;
long long f[N];
int a[N];

void Init ()
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
}

int main ()
{
    Init();
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = a[i]; j <= m; ++j)
        {
            f[j] += f[j - a[i]];
        }
    }
    cout << f[m];
    return 0;
}