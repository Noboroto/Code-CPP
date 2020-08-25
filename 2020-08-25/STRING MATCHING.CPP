/*
https://cses.fi/problemset/task/1753
*/

#include <bits/stdc++.h>

using namespace std;

const int BASE = 31;
const long long oo = 1e9 + 2277;
const int N = 1e7 + 1;

string s, t;
long long nS, nT, hashnumS[N], hashnumT;
long long Pow[N];

void Init ()
{
    cin >> s;
    cin >> t;
    Pow[0] = 1;
    nS = s.length();
    nT = t.length();
    for (int i = 1; i < N; ++i)
    {
        Pow[i] = (BASE * Pow[i - 1]) % oo;
    }
    for (int i = 1; i <= nS; ++i)
    {
        hashnumS[i] = (hashnumS[i - 1] * BASE + (s[i - 1] - 'a' + 1)) % oo;
    }
    for (int i = 0; i < nT; ++i)
    {
        hashnumT = (hashnumT * BASE + (t[i] - 'a' + 1)) % oo;
    }
}

bool Check(const int &left,const int right)
{
    return ((hashnumS[right] - (hashnumS[left - 1] * Pow[right - left + 1]) + oo * oo) % oo ) == hashnumT;
}

int main ()
{
    Init();
    int ans = 0;
    for (int i = 1; i <= nS; ++i)
    {
        if (Check (i, i + nT - 1))
        {
            ans++;
        }
    }
    cout << ans;
    return 0;
}