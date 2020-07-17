#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "CUBICS" + (string)".INP";
    const string FileOUT = "CUBICS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 1e5 + 2;
int n, k, pos = 1e9 + 7, ans = -1e9 - 1;
pair <long long, int> sum[N];

int main ()
{
    Init();
    scanf ("%d%d", &n, &k);
    for (int i = 1 ;i <= n; ++i)
    {
        scanf ("%lld", &sum[i].first);
        sum[i].first -= k;
        sum[i].first += sum[i - 1].first;
        sum[i].second = i;
    }
    sort (sum + 1, sum + n + 2);
    int i = n;
    int previouse = n + 1;
    sum[0].first = 1e18+1;
    while (i >= 0)
    {
        if (sum[i].first != sum[i + 1].first)
        {
            if (i + 1 != previouse) 
            {
                if (ans < sum[previouse].second - sum[i + 1].second)
                {
                    ans = sum[previouse].second - sum[i + 1].second;
                    pos = sum[i + 1].second + 1;
                }
                else if (ans == sum[previouse].second - sum[i + 1].second + 1)
                {
                    pos = min (pos, sum[i + 1].second + 1);
                }
            }
            previouse = i;
        }
        --i;
    }
    if (ans == -1e9-1) printf ("0");
    else printf ("%d %d", ans, pos);
    return 0;
}