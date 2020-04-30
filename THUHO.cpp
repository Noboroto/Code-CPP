#include <iostream>
#include <cstdio>

using namespace std;

int n;
int m, ans = 0, now = 0, past = 0, limit = 0;

void Init ()
{
    cin >> n >> m;
}

int main ()
{
    Init();
    for (int i = 1; i <= n + 1; ++i)
    {
        limit = m;
        if (i <= n) cin >> now; else now = 0;
        ans += min (limit, past);
        limit -= min (limit, past);
        ans += min (limit, now);
        past = now - min (limit, now);
    }
    ans += min (m, now);
    cout << ans;
    return 0;
}