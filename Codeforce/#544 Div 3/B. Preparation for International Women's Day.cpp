/*
https://codeforces.com/contest/1133/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
map <int, int> a;

void Init ()
{
    int x;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> x; 
        a[x % k]++;
    }
}

int main ()
{
    Init();
    int ans = a[0] - (a[0] % 2);
    for (int i = 1; i < k; ++i)
    {
        if (i == k - i) ans += a[i] - (a[i] % 2);
        else ans += min (a[i], a[k - i]) * 2;
        a[i] = 0;
    }
    cout << ans;
    return 0;
}