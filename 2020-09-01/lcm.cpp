#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("lcm.INP", "r", stdin);
    freopen ("lcm.OUT", "w", stdout);
}

long long n;
long long ans;

int main ()
{
    Init();
    cin >> n;
    if (n == 1) ans = 1;
    else if (n == 2) ans = 2;
    else if (n == 3) ans = 6;
    else if (n % 2 != 0) ans = n * (n - 1) * (n - 2);
    else 
    {
        ans = (n - 1) * (n - 2) * (n - 3);
        if (n % 3 != 0) ans = n * (n - 1) * (n - 3);
    }
    cout << ans;
    return 0;
}