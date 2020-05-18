#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int const N = 1e5 + 1;
long long a[N];
int n, k, ans = 0, f[2];
map <long long, int> m;

int main()
{
    freopen("LUCKY.INP", "r", stdin);
    freopen("LUCKY.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        m[a[i]]++;
    }
    int tmp = 0;
    long long am = 0, duong = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (m[a[i]] <= 0)
        {
            f[0] = am;
            f[1] = duong;
        }
        else
        {
            tmp = max (am, duong);
            if (m[k - a[i]] > 0)
            {
                long long kqam = min (m[-k - a[i]], m[a[i]]);
                long long kqduong = max (m[-k -a[i]], m[a[i]]);
                f[0] += tmp;
                f[0] += (kqduong * kqam);
            }
            if (m[k - a[i]] > 0)
            {
                long long kqam = min (m[k -a[i]], m[a[i]]);
                long long kqduong = max (m[k -a[i]], m[a[i]]);
                f[1] += tmp;
                    f[1] += (kqduong * kqam);
            }
            m[-k-a[i]] = 0;
            m[k-a[i]] = 0;
            m[a[i]] = 0;
            am = f[0];
            duong = f[1];
        }
    }
    ans = max (f[0], f[1]);
    cout << ans;
    return 0;
}
