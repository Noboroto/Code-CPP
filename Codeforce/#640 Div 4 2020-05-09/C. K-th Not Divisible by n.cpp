#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "C. K-th Not Divisible by n" + (string)".INP";
    const string FileOUT = "C. K-th Not Divisible by n" + (string)".OUT";
    //freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int t, n, ans, tmp, k;

int main ()
{
    //Init();
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> k;
        tmp = k / (n - 1);
        ans = (n - 1) * tmp + tmp + (k % (n - 1));
        ans -= (ans % n == 0);
        cout << ans << '\n';
    }
    return 0;
}