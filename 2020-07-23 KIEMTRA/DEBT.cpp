#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "DEBT" + (string)".INP";
    const string FileOUT = "DEBT" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

struct Node
{
    int u, v, c;
    Node (int _u = 0, int _v = 0, int _c = 0)
    {
        u = _u;
        v = _v;
        c = _c;
    }
    bool operator < (Node &b)
    {
        if (u < b.u) return true;
        if (u == b.u && v < b.v) return true;
        if (u == b.u && v == b.v && c < b.c) return true;
        return false;
    }
};

const int N = 10 + 1; //2e5;
int n, v, c, head[N], i;
Node a[N];
long long money[N], result;
bool Came[N];
pair <long long, long long> p[N];

void GetData ()
{
    scanf ("%d", &n);
    for ( i = 0; i < n; ++i)
    {
        scanf ("%d%d", &v, &c);
        a[v] = Node (v, i, c);
        head[v]++;
        Came[i] = false;
    }
    for (i = 1; i <= n; ++i)head[i] += head[i - 1];
    sort (a, a + n);
}

long long Recursion (int t, int c)
{
    if (Came[t]) return 0;
    Came[t] = true;
    long long ans = money[i];
    for (i = head[i]; i < head[i + 1]; ++i)
    {
        ans += Recursion(a[i].v, a[i].c);
    }
    result += max ((long long)0, c - ans);
    money[i] = max ((long long)0, ans - c);
    return c;
}

void Trau ()
{
    long long ans = 0;
    scanf ("%d", &n);
    for ( i = 0; i < n; ++i)
    {
        scanf ("%d%d", &v, &c);
        p[i].first += c;
        p[v - 1].second += c;
    }
    for (i = 0; i < n; ++i)
    {
        ans += max ((long long)0, p[i].first - p[i].second);
    }
    printf ("%lld", ans);
}

int main ()
{
    Init();
    Trau();
    return 0;
}