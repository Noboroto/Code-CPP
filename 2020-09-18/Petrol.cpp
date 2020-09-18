#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("Petrol.INP", "r", stdin);
    freopen ("Petrol.OUT", "w", stdout);
}

int n, a, b, c;
vector <pair <int, int> > ans;

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        ans.push_back(make_pair(max (0, (c - b) / a + ((c - b) % a != 0)), i));
    }
    sort (ans.begin(), ans.end());
    cout << ans[0].second;
    return 0;
}