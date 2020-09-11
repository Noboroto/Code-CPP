#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("teleport.INP", "r", stdin);
    freopen ("teleport.OUT", "w", stdout);
}

int n;
long long x;
long long tmp = 0, ans = 1e18 + 1;
vector <long long> a;

int main ()
{
    Init();
    cin >> n;
    a.push_back(0);
    for (int i = 0; i < n; ++i) 
    {
        cin >> x;
        a.push_back(x);
    }
    n++;
    sort (a.begin(), a.end());
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            tmp = 0;
            for (int t = 0; t < n; ++t)
            {
                if (a[t] == a[i] || a[t] == a[j] || a[t] == 0) continue;
                tmp += min (abs (a[t] - a[j]) + abs (a[i]), min (abs(a[t] - a[i]) + abs(a[j]), abs(a[t])));
            }
            ans = min (ans, tmp);
        }
    }
    cout << ans;
    return 0;
}