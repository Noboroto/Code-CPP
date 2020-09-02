#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("quyhoachdong.INP", "r", stdin);
    freopen ("quyhoachdong.OUT", "w", stdout);
}

int a, b, c, m;

int main ()
{
    Init();
    while (cin >> a)
    {
        cin >> b >> c >> m;
        if (m < 3) cout << "Yes ";
        else if (a < 1 || b < 1 || c < 1) cout << "Yes ";
        else if (a + b + c < m) cout << "Yes ";
        else cout << "No ";
    }
    return 0;
}