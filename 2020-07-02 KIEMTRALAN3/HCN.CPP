#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "HCN" + (string)".INP";
    const string FileOUT = "HCN" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int main ()
{
    //Init();
    int n, m, ans = 0, tmp;
    cin >> n >> m;
    if (n < m) swap (m, n);
    while (m > 0 && n > 0)
    {
        if (n % m == 0) tmp = m;
        else tmp = m/2;
        ans += n / tmp;
        m -= tmp;
    }
    cout << ans;
    return 0;
}