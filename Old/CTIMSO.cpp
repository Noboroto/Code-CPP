#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
    freopen ("ctimso.inp","r",stdin);
    freopen ("ctimso.out","w",stdout);
    cin >> n >> m;
    map<int, int> M;
    for (long long i=2; i<=46900; i++)
    {
        if (m % i == 0)
        {
            int b = 0;
            while (m % i == 0)
            {
                m /= i;
                b++;
            }
            M[i] = b;
        }
    }
    int rr = 2e9;
    for (auto x: M)
    {
        int d = x.first , c = 0, a = n;
        while (a)
        {
            c += a / d;
            a /= d;
        }
        rr = min(rr, c / x.second);
    }
    cout << rr;
    return 0;
}
