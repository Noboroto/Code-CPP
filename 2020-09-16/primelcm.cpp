#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

void Init ()
{
    freopen ("primelcm.INP", "r", stdin);
    freopen ("primelcm.OUT", "w", stdout);
}

struct Num
{
    ll val, pos;
    Num (ll v = 0, ll p = 0)
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

const ll N = 1e7 + 1;
const ll oo = 998244353;
const ll T = 1e5 + 1;

bool IsNotPrime[N];
vector<ll> MulNum[7*T];
ll PrimeNum[7*T];
ll t = 0;

void Prepare (ll limit)
{
    ll tmp = 1;
    limit++;
    for (ll i = 2; i < N; ++i)
    {
        if (IsNotPrime[i]) continue;
        tmp = i * i;
        for (ll j = i; j*i < N; ++j)
        {
            IsNotPrime[i*j] = true;
        }
        while (tmp <= limit)
        {
            MulNum[t].push_back(tmp);
            if (limit/i < tmp) break;
            else tmp *= i;
        }
        PrimeNum[t] = i;
        t++;
    }
}

ll n, i;
Num Query[T];
ll ans[T], q[T];

void Solve (ll n)
{
    ll k = 0, j;
    for (i = 0; i <= t; ++i)
    {
        if (MulNum[i].size() < 1 || MulNum[i][0] > Query[n - 1].val) break;
        for (j = 0; j < MulNum[i].size(); ++j)
        {
            if (MulNum[i][j] > Query[n - 1].val) break;
            k = lower_bound(Query, Query + n, Num(MulNum[i][j], 0)) - Query;
            q[k] = (q[k] * PrimeNum[i] ) % oo;
        }
    }
    for (i = 0; i < n; ++i)
    {
        if (i > 0) q[i] = ((q[i-1] % oo) * (q[i] % oo)) % oo;
        ans[Query[i].pos] = q[i];
    }
}

void Get(ll &a)
{
    a = 0;
    char c = 'a';
    while (true)
    {
        c = getchar();
        if (c < '0' || c > '9') break;
        a = a*10 + (c - '0');
    }
}

void Put (ll a)
{
    if (a >= 10) Put(a / 10);
    putchar(a % 10 + '0');
}

int main ()
{
    Init();
    Get(n);
    for (ll i = 0; i < n; ++i)
    {
        Get(Query[i].val);
        Query[i].pos = i;
        ans[i] = 0;
        q[i] = 1;
    }
    sort(Query, Query + n);
    Prepare(Query[n-1].val);
    Solve(n);
    for (ll i = 0; i < n; ++i) 
    {
        Put (ans[i]);
        putchar(' ');
    }
    return 0;
}