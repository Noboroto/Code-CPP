#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "SEQMAX" + (string)".INP";
    const string FileOUT = "SEQMAX" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 1e4 + 1;
int n, a[N];

int Solve ()
{
    int j, tmp = 0, ans = 0;
    for (int i = 0; i < n; ++i)
    {
        tmp = 0;
        for (j = i; j < n; ++j)
        {
            tmp += a[j];
            if (tmp > 0) ans = max (ans, j - i + 1);
        }
    }
    return ans;
}   

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << Solve();
    return 0;
}