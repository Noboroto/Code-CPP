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
vector <ll> PrimeNum;

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

const int T = 1e5 + 1;
int n, i;
Num Query[T];
ll ans[T], q[T];

void Solve (int n)
{
    ll tmp;
    int k = 0;
    for (i = 0; i < PrimeNum.size(); ++i)
    {
        tmp = (PrimeNum[i]*PrimeNum[i]) % oo;
        if (tmp > Query[n - 1].val) break;
        while (tmp <= Query[n - 1].val)
        {
            k = lower_bound(Query, Query + n, Num(tmp, 0)) - Query;
            q[k] = (q[k] * PrimeNum[i]) % oo;
            tmp = (PrimeNum[i] * tmp) % oo;
        }
    }
    for (i = 0; i < n; ++i)
    {
        if (i > 0) q[i] = (q[i-1] * q[i]) % oo;
        ans[Query[i].pos] = q[i];
    }
}

void Get(int &a)
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
    Prepare();
    Get(n);
    for (int i = 0; i < n; ++i)
    {
        Get(Query[i].val);
        Query[i].pos = i;
        ans[i] = 0;
        q[i] = 1;
    }
    sort(Query, Query + n);
    Solve(n);
    for (int i = 0; i < n; ++i) 
    {
        Put (ans[i]);
        putchar(' ');
    }
    return 0;
}