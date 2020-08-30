#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("phi.INP", "r", stdin);
    freopen ("phi.OUT", "w", stdout);
}

int eulerPhi(int n) 
{
    if (n == 0) return 0;
    int ans = n;
    for (int x = 2; x*x <= n; ++x) {
        if (n % x == 0) {
            ans -= ans / x;
            while (n % x == 0) n /= x;
        }
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

int main ()
{
    Init();
    int n;
    cin >> n;
    cout << eulerPhi(n);
    return 0;
}