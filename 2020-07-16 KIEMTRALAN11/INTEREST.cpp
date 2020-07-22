#include <bits/stdc++.h>

using namespace std;

void Init()
{
    const string FileINP = "INTEREST" + (string) ".INP";
    const string FileOUT = "INTEREST" + (string) ".OUT";
    freopen(FileINP.c_str(), "r", stdin);
    freopen(FileOUT.c_str(), "w", stdout);
}

const int N = 1e5 + 1;
int n, s, sum[N], ans[N];

int main()
{
    Init();
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &sum[i]);
        sum[i] += sum[i - 1];
    }
    int left, right, distance = 0, length = 0;
    for (int i = 1; i < n; ++i)
    {
        left = lower_bound (sum, sum + i + 1, sum[i] - s) - sum  + 1;
        right = upper_bound (sum + i + 1, sum + n + 1, s + sum[i]) - sum  - 1;
        distance = min (right - (i + 1), i - left);
        while (distance >= 0)
        {
            ans[i - distance] = max (2 * (distance + 1), ans[i - distance]); 
            --distance;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        printf ("%d\n", ans[i]);
    }
    return 0;
} 