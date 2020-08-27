#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("password.INP", "r", stdin);
    freopen ("password.OUT", "w", stdout);
}

int main ()
{
    Init();
    int t, ans = 0;
    string s;
    cin >> s;
    cin >> t;
    for (int i = 0; i < s.length(); ++i)
    {
        ans += (s[i] - 'a' + t) % 26;
    }
    cout << ans;
    return 0;
}