#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("line.INP", "r", stdin);
    freopen ("line.OUT", "w", stdout);
}

const int oo = 998244353;
vector <int> Giaithua;
map <int, int> Counting;
int t;
int n, k, x;

void Prepare (int n)
{
    if (n < Giaithua.size()) return;
    for (int i = Giaithua.size(); i <= n; ++i)
    {
        Giaithua.push_back((Giaithua[i - 1] * i) % oo);
    }
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Init();
    Giaithua.push_back(1);
    cin >> t;
    cin >> n >> k; 
    int tmp = 0, ans = 1;
    Prepare(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        Counting[x]++;
        tmp = max (tmp, x);
    }
    if (t == 1)
    {
        for (int i = 1; i <= tmp; ++i)
        {
            ans = (ans * Giaithua[Counting[i]]) % oo; 
        }
        cout << ans;
    }
    else
    {
        cout << Giaithua[n];
    }
    return 0;
}