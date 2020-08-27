#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 1;
const ll oo = 1e9 + 7;
map <char, int> counter;
ll factorial[N];

void Init ()
{
    factorial[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        factorial[i] = (factorial[i - 1] * i) % oo;
    }
}

ll Pow (ll a, ll n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    ll t = Pow (a, n / 2) % oo;
    if (n % 2 == 0) return (t * t) % oo;
    else return ((t * t) % oo) * a % oo; 
}

int main ()
{
    Init();
    string s;
    int n;
    ll ans = 1;
    cin >> s;
    n = s.length();
    for (int i = 0; i <n; ++i)
    {
        counter [s[i]] ++;
    }
    for (char i = 'a'; i <= 'z'; ++i)
    {
        ans = (ans * factorial[counter[i]]) % oo;
    }
    ans = Pow (ans, oo - 2) % oo;
    ans = (factorial[n] * ans) % oo;
    cout << ans;
    return 0;
}