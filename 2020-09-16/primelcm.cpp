#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("primelcm.INP", "r", stdin);
    freopen ("primelcm.OUT", "w", stdout);
}

typedef long long ll;

const int N = 1e7 + 1;
const ll oo = 998244353;

bool IsPrime[N];
ll ans[N];

void Prepare ()
{
    for (ll i = 0; i < N; ++i)
    {
        ans[i] = 1;
        IsPrime[i] = true;
    }
    ll tmp = 1;
    for (ll i = 2; i < N; ++i)
    {
        ans[i] = (ans[i] * ans[i - 1]) % oo;
        if (!IsPrime[i]) continue;
        tmp = i * i;
        for (ll j = 2; j*i < N; ++j)
        {
            IsPrime[i*j] = false;
            if (j*i == tmp)
            {
                tmp *= i;
                ans[i * j] = (ans [i * j] * i) % oo;
            }
        }
    }
}

int t;

int main ()
{
    Init();
    Prepare();
    cin >> t;
    int n;
    for (int i = 0; i < t; ++i)
    {
        cin >> n;
        if (n < N) cout << ans[n] << " ";
        else cout << "0 ";
    }
    return 0;
}