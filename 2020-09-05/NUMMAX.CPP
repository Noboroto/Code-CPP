#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

queue <int> Waiting;
ll b;
int n;
vector <ll> a;

void Init ()
{
    freopen ("NUMMAX.INP", "r", stdin);
    freopen ("NUMMAX.OUT", "w", stdout);
}

ll GetCounting (int pos)
{
    int l = pos;
    int r = pos;
    while (a[l] <= b && l >= 0) l--;
    while (a[r] <= b && r < n) r++;
    l++, r--;
    int dis = (r - pos + 1) + (pos - l);
    dis += (r - pos) * (pos - l); 
    return dis;
}

int main ()
{
    Init();
    int x;
    cin >> n >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        a.push_back(x);
        if (x == b) Waiting.push(i);
    }
    ll ans = 0;
    while (!Waiting.empty())
    {
        ans += GetCounting(Waiting.front());
        Waiting.pop();
    }
    cout << ans;
    return 0;
}