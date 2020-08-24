#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
vector <int> divisors[N];
int n, f[N], a[N], ans;

void Init ()
{
    for (int i = 1; i < N; ++i)
    {
        for (int j = i * 2; j < N; j += i)
        {
            divisors[j].push_back(i);
        }
    }
}

void GetData()
{
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &a[i]);
    }
}

int Solve ()
{
    int ans = 1;
    for (int i = 1; i <= n; ++i)
    {
        f[i] = 1;
        for (int j = 0; j < divisors[i].size();++j)
        {
            if (a[divisors[i][j]] >= a[i]) continue;
            f[i] = max (f[i], f[divisors[i][j]] + 1);
        }
        ans = max (ans, f[i]);
    }
    return ans;
}

int main ()
{
    Init();
    int t;
    scanf ("%d", &t);
    while (t > 0)
    {
        t--;
        GetData();
        ans = Solve ();
        printf ("%d\n", ans);
    }
    return 0;
}