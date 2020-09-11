#include <bits/stdc++.h>

using namespace std;

void Init()
{
    freopen ("DIVSEQ.INP", "r", stdin);
    freopen ("DIVSEQ.OUT", "w", stdout);
}

const int N = 5e4 + 1;
int n, d, t;
long long a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Init();
    cin >> t;
    while (t > 0)
    {
        t--;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        long long ans = 0;
        for (int i = 1; i <=n ; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if ((a[j] - a[i - 1]) % d == 0) ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
