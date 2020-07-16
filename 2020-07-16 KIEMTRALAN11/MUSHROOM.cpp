#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "MUSHROOM" + (string)".INP";
    const string FileOUT = "MUSHROOM" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

long long sum[11];
vector <long long> Lon, Be;

int main ()
{
    long long ans = 0;
    Init();
    for (int i = 1; i <= 10; ++i)
    {
        scanf ("%lld", &sum[i]);
        sum[i] += sum[i-1];
    }

    for (int i = 1; i <= 10; ++i)
    {
        for (int j = i; j <= 10; ++j)
        {
            if (sum[j] - sum[i - 1] >= 100) Lon.push_back(sum[j] - sum[i - 1]);
            else Be.push_back(sum[j] - sum[i - 1]);
        }
    }

    sort (Lon.begin(), Lon.end());
    sort (Be.begin(), Be.end());

    if (Lon.empty()) ans = Be.back();
    else if (Be.empty())ans = Lon[0];
    else ans = (Lon[0] - 100 > 100 - Be.back()) ? Be.back() : Lon[0];

    printf ("%lld", ans);
    return 0;
}