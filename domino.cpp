#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void Init ()
{
    freopen("DOMINO.INP","r", stdin);
    freopen("DOMINO.OUT","w", stdout);
}

bool CanSwap[51], ans[51];
ll dif = 0, tmpC = 1e9 + 7;
int n;
pair<ll, ll> a[51];

void Trau (ll pos, ll sumT, ll sumD, int Counting)
{
    if (pos == n)
    {
       if (abs (sumT - sumD) <= dif)
       {
           if (abs (sumT - sumD) == dif && Counting >= tmpC) return;
           dif = abs(sumD - sumT);
           tmpC = Counting;
           for (int i = 0; i < n; ++i) ans[i] = CanSwap[i];
       }
       return;
    }
    CanSwap[pos] = false;
    Trau (pos + 1, sumT + a[pos].first, sumD + a[pos].second, Counting);
    CanSwap[pos] = true;
    Trau (pos + 1, sumT + a[pos].second, sumD + a[pos].first, Counting + 1);
    CanSwap[pos] = false;
}

void Solve ()
{
    vector < pair<ll, int> > need;
    ll sum = 0, ans = abs (dif);
    int l, r;
    for (ll i = 0; i < n; ++i)
    {
        need.push_back(make_pair(a[i].second - a[i].first - a[i].first + a[i].second, i));
    }
    sort (need.begin(), need.end());
    for (int i = 0; i < n; ++i)
    {
        sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum += need[j].first;
            if (abs (sum + dif) < ans)
            {
                ans = abs (sum + dif);
                l = i;
                r = j;
            }
        }
    }
    if (ans >= abs(dif))
    {
        cout << ans << " " << 0;
    }
    else
    {
        vector <int> pos;
        for (int i = l; i <= r; ++i)
        {
            pos.push_back(need[i].second);
        }
        sort (pos.begin(), pos.end());
        cout << ans << " " << pos.size() << "\n";
        for (int i = 0; i < (int)pos.size(); ++i)
        {
            cout << pos[i] + 1 << " ";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL)
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].second;
        dif += a[i].first - a[i].second;
    }
    if (n <= 20)
    {
        ll ta = dif;
        dif = abs (dif);
        Trau(0,0,0,0);
        cout << dif << " " << tmpC << "\n";
        for (int i = 0; i < n; ++i)
        {
            if (ans[i]) cout << i + 1<< " ";
        }
        cout << "\n\n";
        dif = ta;
    }
    else
    {
        Solve();
    }
    return 0;
}
