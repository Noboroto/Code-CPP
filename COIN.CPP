#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void Init ()
{
    const string FileINP = "COIN" + (string)".INP";
    const string FileOUT = "COIN" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

long long n, k;
vector <long long> o, r;
map <long long, long long> a;
long long ans = 0;

int main ()
{
    Init();
    cin >> n >> k;
    o.push_back(0);
    r.push_back(0);
    for (long long i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        o.push_back(o[i - 1] + (int)(c == 'O'));
        r.push_back(r[i - 1] + (int)(c == 'R'));
        long long x = o[i] - k*r[i];
        if (a[x] == 0) a[x] = i;
        else ans = max (ans, (i - a[x]));
        if (o[i] == r[i]*k) ans = max (ans, i);
    }
    cout << ans;
    return 0;
}