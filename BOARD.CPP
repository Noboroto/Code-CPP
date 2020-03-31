#include <iostream>
#include <cstdio>

using namespace std;

void Init ()
{
    const string FileINP = "BOARD" + (string)".INP";
    const string FileOUT = "BOARD" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int oo = 1e9 + 7;
int m, n;

int main ()
{
    Init();
    cin >> n >> m;
    return 0;
}