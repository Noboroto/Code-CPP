/*
https://codeforces.com/contest/650/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <pair <ll, ll>> x , y;
ll ans = 0, tmp;
ll n, s, t;

ll GetSum (ll t)
{
    return t * (1 + t) / 2;
}

int main ()
{
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> s >> t;
        x.push_back (make_pair(s, t));
        y.push_back (make_pair(t, s));
    }
    sort (x.begin(), x.end());
    sort (y.begin(), y.end());
    x.push_back(make_pair(1e9 + 7, 1e9 + 7));
    y.push_back(make_pair(1e9 + 7, 1e9 + 7));
    tmp = 1;
    for (ll i = 1; i <= n; ++i)
    {
        if (x[i].first != x[i - 1].first)
        {
            ans += GetSum(tmp - 1);
            tmp = 0;
        }
        tmp++;
    }
    tmp = 1;
    ll same = 0;
    for (ll i = 1; i <= n; ++i)
    {
        if (y[i] != y[i - 1] && same > 0)
        {
            ans -= GetSum (same);
            same = 0;
        }
        if (y[i].first != y[i - 1].first)
        {
            ans += GetSum(tmp - 1);
            tmp = 0;
        }
        tmp++;
        same += (y[i] == y[i - 1]);
    }
    cout << ans;
    return 0;
}