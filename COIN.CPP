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
    last.push_back(0);
    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        o.push_back(o[i - 1] + (int)(c == 'O'));
        r.push_back(r[i - 1] + (int)(c == 'R'));
        if (r[i] == r[i - 1]) last.push_back(last[i - 1]);
        else last.push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            int SLO = o[j] - o[i - 1];
            int SLR = r[j] - r[i - 1];
            if (SLO  == SLR * k) ans = max (ans, j - i + 1);
        }
    }
    cout << ans;
    return 0;
}