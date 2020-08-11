#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "CMAX" + (string)".INP";
    const string FileOUT = "CMAX" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e5 + 1; //1e5
int n, m;
pair <long long, long long> a[N];

void input ()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf ("%lld%lld", &a[i].first, &a[i].second);
    }
    scanf ("%d", &m);
}

void Trau ()
{
    
}

int main ()
{
    Init();
    input();
    long long x = 0;
    while (m > 0)
    {
        m--;
        scanf ("%lld",&x);
        long long ans = -1e18-7;
        for (int i = 0; i < n; ++i) 
            ans = max (ans, a[i].first * x + a[i].second);
        printf ("%lld\n", ans);
    }
    return 0;
}