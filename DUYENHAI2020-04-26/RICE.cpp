#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n, k, m, ans = 0;
vector <int> Supectors;
vector <bool> Check;

void Init ()
{
    const string FileINP = "RICE" + (string)".INP";
    const string FileOUT = "RICE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
    cin >> m >> n >> k;
    for (int i = 0; i < m; ++i) Check.push_back(false);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        Supectors.push_back(x);
        Check[x] = true;
    }
    sort (Supectors.begin(), Supectors.end());
}

void Process (int i, int sum)
{
    if (i >= m)
    {
        ans = min (ans, sum);
    }
    for (int i = 0; i < n; ++i)
    {
        if 
    }
}

int main ()
{
    Init();
    int i = 0, ans = 0;

    cout << ans;
    return 0;
}