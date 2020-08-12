#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("US.INP", "r", stdin);
    freopen ("US.OUT", "w", stdout);
}

const int N = 1e6 + 1;
typedef long long ll;
pair <ll, ll> a[N];
ll t, x, y, i, j;

void Prepare ()
{
    a[1].first = 1;
    a[1].second = 1;
    for (i = 2; i < N; ++i)
    {
        for (j = 1; j < N; ++j)
        {
            if (i * j >= N) break;
            a[i*j].first ++;
            a[i*j].second += i;
        }
        a[i].first += a[i - 1].first + 1;
        a[i].second += a[i - 1].second + 1;
    }
}

void GetInt (ll &x)
{
    x = 0;
    i = (' ');
    while (i > ('9') || i < ('0')) i = getchar();
    do 
    {
        x = x * 10 + i - '0';
        i = getchar();
    }
    while (i <= ('9') && i >= ('0'));
}

void PutInt(const ll b)
{
    if (b < 10) putchar(b + '0');
    else 
    {
        PutInt(b / 10);
        putchar((b % 10) + '0');
    }
}

int main ()
{
    ios_base::sync_with_stdio(0);
    Init();
    Prepare();
    GetInt(t);
    ll s;
    while (t > 0)
    {
        t--;
        GetInt(x);
        GetInt(y);
        s = a[y].first - a[x - 1].first;
        PutInt(s);
        putchar (' ');
        s = a[y].second - a[x - 1].second;
        PutInt(s);
        putchar ('\n');
    }
}