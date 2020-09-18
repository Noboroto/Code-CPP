#include <cstdio>
#include <iostream>

using namespace std;

void Init ()
{
    freopen ("Petrol.INP", "r", stdin);
    freopen ("Petrol.OUT", "w", stdout);
}

int n;
int a, b, c;
long double ans = 1e9 + 7, pos, tmp;

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie (NULL);
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c;
        tmp = (long double) a / (long double)(c - b);
        if (ans > tmp)
        {
            ans = tmp;
            pos = i + 1;
        }
    }
    cout << pos;
    return 0;
}
