#include <iostream>
#include <cstdio>

using namespace std;

int n;
long long m, ans = 0, now, future;

void Init ()
{
    cin >> n >> m;
    now = 0;
    future = 0;
}

int main ()
{
    Init();
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        now += x;
        future = max ((long long)0, now - m);
        ans += min (m, now);
        now = future;
        future = 0;
    }
    ans += min (m, now);
    cout << ans;
    return 0;
}