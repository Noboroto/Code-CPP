#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "CNTSEQ" + (string)".INP";
    const string FileOUT = "CNTSEQ" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e3 + 1;
int n, m, a[N];

long long Solve (int l, int r)
{
    long long ans = 0;
    int tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        tmp = 0;
        for (int j = 1; j <= n; ++j)
        {
            tmp = max (tmp, a[j]);
        }
        if (l <= tmp && tmp <= r) ans++;
    }
    return ans;
}

int main ()
{
    Init();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    int l, r;
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        cout << Solve (l, r);
    }
    return 0;
}