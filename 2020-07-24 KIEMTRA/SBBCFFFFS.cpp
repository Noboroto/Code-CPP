#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "SBBCFFFFS" + (string)".INP";
    const string FileOUT = "SBBCFFFFS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int main ()
{
    int n;
    Init();
    cin >> n;
    for (int i = 1; i <= n;++i) cout << i << ' ';
    return 0;
}