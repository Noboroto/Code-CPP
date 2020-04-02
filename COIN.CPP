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

int n, k;
vector <int> last, o, r;

int main ()
{
    Init();
    cin >> n >> k;
    o.push_back(0);
    r.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        o.push_back(o[i - 1] + (int)(c == 'O'));
        r.push_back(r[i - 1] + (int)(c == 'R'));
    }
    int ans = 0;
    for (int i = 15; i <= 15; ++i)
    {
        if (o[i] - r[i]*k < 0) continue; 
        int j = upper_bound (o.begin(), o.end(), o[i] - r[i]*k) - o.begin();
        ans = max (ans, i - j + 1);
    }
    cout << ans;
    return 0;
}