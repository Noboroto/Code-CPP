#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("primelcm.INP", "r", stdin);
    freopen ("primelcm.OUT", "w", stdout);
}

struct Num
{
    int val, pos;
    Num (int v = 0, int p = 0)
    {
        val = v;
        pos = p;
    }
    bool operator < (const Num &b) const
    {
        if (val < b.val) return true;
        if (val == b.val && pos < b.pos) return true;
        return false;
    }
};

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
vector <Num> Query;
ll ans[N];

vector<int> Solve (int n)
{
    vector <int> ans (n, 1), q;
    for (int i = 0; i < Query.size(); ++i) q.push_back(Query[i].val);
    ll tmp;
    int k = 0;
    for (int i = 0; i < PrimeNum.size(); ++i)
    {
        tmp = (PrimeNum[i]*PrimeNum[i]) % oo;
        while (tmp < Query.back().val)
        {
            k = lower_bound(q.begin(), q.end(), tmp) - q.begin();
            if (k >= Query.size()) break;
            ans[Query[k].pos] = (ans[Query[k].pos] * (tmp / PrimeNum[i])) % oo;
            while (Query[k].val == Query[k + 1].val && k < Query.size())
            {
                k++;
                ans[Query[k].pos] = (ans[Query[k].pos] * (tmp / PrimeNum[i])) % oo;
            }
            tmp = (PrimeNum[i] * tmp) % oo;
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
        Query.push_back(Num(x, i));
    }
    sort(Query.begin(), Query.end());
    vector <int> ans = Solve(t);
    for (int i = 0; i < t; ++i) cout << ans[i] << " ";
    return 0;
}