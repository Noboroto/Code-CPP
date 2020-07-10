#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "LIS" + (string)".INP";
    const string FileOUT = "LIS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e6 + 1;
int sum = 0, n;
int ans = 1e9 + 7;

int main ()
{
    Init();
    scanf ("%d", &n);
    int j = 0, maxval = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf ("%d", &j);
        sum += j;
        ans = min (sum - maxval, ans);
        maxval = max (maxval, sum);
    }
    printf("%d", ans);
    return 0;
}