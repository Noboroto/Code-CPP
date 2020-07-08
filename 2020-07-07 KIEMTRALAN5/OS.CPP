#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "OS" + (string)".INP";
    const string FileOUT = "OS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e6 + 1;
pair <int, int> Query [N], Compact [N];

void CompactArray (int n)
{
    sort (Compact, Compact + 2 * n);
    for (int i = 1; i <= n; ++i)
    {
        if (Query[Compact[i].second].first == Compact[i].first) Query[Compact[i].second].first = i;
        if (Query[Compact[i].second].second == Compact[i].first) Query[Compact[i].second].second = i;
    }
}

int n, m, a[2*N];
bool b[N];

int main ()
{
    Init();
    cin >> m >> n;
    int u, v;
    for (int i = 1; i <= n; ++i)
    {
        cin >> u >> v;
        Query[i] = make_pair (u, v);
        Compact[i] = make_pair (u, i);
        Compact[i + n] = make_pair (v, i);
        b[i] = true;
    }
    CompactArray (n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = Query[i].first; j <= Query[i].second; ++j)
        {
            b[a[j]] = false;
            a[j] = i;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans += b[i];
    }
    cout << ans;
    return 0;
}