#include <bits/stdc++.h>

using namespace std;

bool Compare (const string &s, const string &t)
{
    return ((s + t) > (t + s));
}

const int N = 1e5 + 1;
int n;
string a[N];

int main ()
{
    freopen("MAXV.INP", "r", stdin);
    freopen("MAXV.OUT", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort (a, a + n, Compare);
    for (int i = 0; i < n; ++i) cout << a[i];
    return 0;
}