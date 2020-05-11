#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "B. Same Parity Summands" + (string)".INP";
    const string FileOUT = "B. Same Parity Summands" + (string)".OUT";
    //freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int t, k, n;

int main ()
{
    //Init();
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> k;
        if (n % 2 != 0 && k % 2 == 0 || k > n)
        {
            cout << "NO\n";
            continue;
        }
        if ((n % 2 == 0 && k % 2 == 0) || ((n % 2 != 0 && k % 2 != 0)))
        {
            cout << "YES\n";
            for (int j = 1; j < k; ++j)
            {
                cout << 1 << ' ';
                n--;
            }
            cout << n << '\n';
        }
        if (n % 2 == 0 && k % 2 != 0)
        {
            if (n <= (k - 1)*2)
            {
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
            for (int j = 1; j < k; ++j)
            {
                cout << 2 << ' ';
                n-=2;
            }
            cout << n << '\n';
        }
    }
    return 0;
}