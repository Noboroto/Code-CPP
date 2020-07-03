#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "HOMEWORK" + (string)".INP";
    const string FileOUT = "HOMEWORK" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e4 + 1;
int n, m;
long long Val[N], sum;
bool Cannot [N];

int main ()
{
    Init();
    sum = 0;
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &Val[i]);
        sum += Val[i];
    }
    int u, v;
    for (int i = 0; i < m; ++i)
    {
        scanf ("%d %d", &u, &v);
        Cannot [u] = true;
    }
    long long tmp = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (Cannot[i]) continue;
        tmp = max (tmp, Val[i]);
    }
    sum -= tmp;
    cout << sum;
    return 0;
}