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

int main ()
{
    //Init();
    Prepare();\
    int sum = 0;
    for (int i = 2; i < N ; ++i)
    {
        if (IsPrime[i]) sum++;
    }
    cout << sum;
    return 0;
}