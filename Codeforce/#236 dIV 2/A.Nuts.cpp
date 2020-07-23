#include <bits/stdc++.h>

using namespace std;

void Init ()
{
}

int k, a, b, v;

int main ()
{
    Init();
    cin >> k >> a >> b >> v;
    long long ans = 0;
    k--;
    int j = k;
    while (a > 0)
    {
        a -= v;
        if (a < 1 || j < 1 || b < 1)
        {
            ans++;
            if (j < 1) j = k;
            continue;
        }
        if (j > 0 && b > 0)
        {
            j--;
            b--;
        }
    }
    cout << ans;
    return 0;
}