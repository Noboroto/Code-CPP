#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("Petrol.INP", "r", stdin);
    freopen ("Petrol.OUT", "w", stdout);
}

int n;
long double a, b, c;
vector <pair <long double, int> > ans;

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        ans.push_back(make_pair(max ((long double)0, (c - b) / a), (long double)i));
    }
    sort (ans.begin(), ans.end());
    cout << ans[0].second;
    return 0;
}