#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "BIRTHDAY" + (string)".INP";
    const string FileOUT = "BIRTHDAY" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int q, m, n, ans = 0;

void Reverse (int gc, int sum, int n)
{
    if (n <= 0)
    {
        ans += (sum == m && gc <= 1);
        return;
    }
    for (int i = 1; i <= m - sum; ++i)
    {
        if (sum == 0) gc = i;
        Reverse (__gcd (gc, i), sum + i, n - 1);
    }
}


int main ()
{
    Init();
    cin >> q;
    while (q > 0)
    {
        ans = 0;
        cin >> m >> n;
        Reverse(1e9+7,0,n);
        cout << ans << '\n';
        q--;
    }
    return 0;
}