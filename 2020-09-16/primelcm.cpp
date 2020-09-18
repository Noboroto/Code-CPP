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
vector <int> PrimeNum;

void Prepare ()
{
    for (ll i = 0; i < N; ++i)
    {
        IsPrime[i] = true;
    }
    ll tmp = 1;
    for (ll i = 2; i < N; ++i)
    {
        if (!IsPrime[i]) continue;
        PrimeNum.push_back(i);
        for (ll j = 2; j*i < N; ++j)
        {
            IsPrime[i*j] = false;
        }
    }
}

int t;
ll x;
vector <pair <ll, int>> Query;
ll ans[N];

vector<int> Solve (int n)
{
    vector <int> ans (n, 1);
    ll tmp;
    int k = 0;
    for (int i = 0; i < PrimeNum.size(); ++i)
    {
        tmp = PrimeNum[i]*PrimeNum[i];
        while (tmp < Query.back().second)
        {
            k = lower_bound(Query.begin(), Query.end(), make_pair(k, 0)) - Query.begin();
            if (k >= Query.size()) break;
            ans[Query[k].second] = (ans[Query[k].second] * (tmp / PrimeNum[i])) % oo;
            while (Query[k].first == Query[k].first)
            {
                k++;
                ans[Query[k].second] = (ans[Query[k].second] * (tmp / PrimeNum[i])) % oo;
            }
        }
    }
    return ans;
}

int main ()
{
    //Init();
    Prepare();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> x;
        Query.push_back(make_pair(x, i));
    }
    sort(Query.begin(), Query.end());
    vector <int> ans = Solve(t);
    for (int i = 0; i < t; ++i) cout << ans[i] << " ";
    return 0;
}