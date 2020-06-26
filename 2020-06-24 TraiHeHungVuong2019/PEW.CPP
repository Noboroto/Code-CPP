#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "PEW" + (string)".INP";
    const string FileOUT = "PEW" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int oo = 1e9 + 7;
int n;
long long ans = 1, a = 1;
map <char, int> check;

long long pow (long long a, long long n, long long MOD)
{
    if (n <= 0) return 1;
    if (n == 1) return a % MOD;
    long long tmp = (pow (a, n / 2, MOD)) % MOD;
    if (n % 2 == 0) return (tmp * tmp)% MOD;
    else return ((tmp * tmp) % oo * a) % MOD;
}

int main ()
{
    string s;
    //Init();
    cin >> s;
    n = s.length();
    for (int i = 0; i < s.length(); ++i)
    {
        check[s[i]]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        ans = (ans * i) % oo;
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if (check[s[i]] < 2) continue;
        for (int j = 1; j <= check[s[i]]; ++j)
        {
            a = (a * j) % oo;
        }
        check[s[i]] = 0;
    }
    long long result = ((ans % oo )* pow (a, oo - 2, oo)) % oo;
    cout << result;
    return 0;
}