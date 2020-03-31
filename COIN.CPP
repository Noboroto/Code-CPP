#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "COIN" + (string)".INP";
    const string FileOUT = "COIN" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int N = 20;
int n, k;
int o[N], r[N];
int ans = 0;

int main ()
{
    Init();
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        o[i] = o[i - 1] + (int)(c == 'O');
        r[i] = r[i - 1] + (int)(c == 'R');
    }
    int maxr = r[n];
    while (maxr > 0)
    {
        int id = upper_bound(o + 1, o + n + 1)
    }
    cout << ans;
    return 0;
}