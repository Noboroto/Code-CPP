#include <iostream>
#include <cstdio>

using namespace std;

void Init()
{
    const string FileINP = "REC" + (string)".INP";
    const string FileOUT = "REC" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

long long n,m,p;
long long ans;

int main()
{
    Init();
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        if ((i+j)*2 >= p)
        {
            long long x = n - i + 1;
            long long y = m - j + 1;
            ans += x*y;
        }
    }
    cout << ans;
    return 0;
}
