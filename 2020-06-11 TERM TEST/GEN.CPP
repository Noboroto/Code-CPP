#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "GEN" + (string)".INP";
    const string FileOUT = "GEN" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int t;
int m;

int Solve (int m)
{
    int tmp = 0, a = 0;
    for (int i = m/2; i < m; ++i)
    {
        a = i;
        tmp = a;
        while (a > 0)
        {
            tmp += a % 10;
            a /= 10;
        }     
        if (tmp == m) return i;
    }
    return 0;
}

int main ()
{
    Init();
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> m;
        cout << Solve(m) << '\n';
    }
    return 0;
}