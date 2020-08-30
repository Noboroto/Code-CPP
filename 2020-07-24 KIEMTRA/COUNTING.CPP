#include <bits/stdc++.h>
using namespace std;

void Init ()
{
    const string FileINP = "COUNTING" + (string)".INP";
    const string FileOUT = "COUNTING" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n;
long long ans = 0, xy, xz, yz;

map <long long, bool> sq;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Init();
    cin >> n;
    for (long long x = 1; x <= n; ++x)
    {
        for (long long y = x + 1; y <= n; ++y)
        {
            xy = sqrt (x * y);
            if (xy * xy != (x * y)) continue;
            for (long long z = y + 1; z <= n; ++z)
            {
                xz = sqrt (x * z);
                yz = sqrt (y * z);
                ans += (xz * xz == (x * z) && yz * yz == (y * z));
            }
        }
    }
    cout << ans;
    return 0;
}