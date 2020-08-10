#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

void Init ()
{
    const string FileINP = "FGARDEN" + (string)".INP";
    const string FileOUT = "FGARDEN" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int n, t, ans = 0;
vector <int> a;

int main ()
{
    Init();
    cin >> n >> t;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x); 
    }
    for (int i = 0; i < n; ++i)
    {
        int maximum = a[i], minimum = a[i];
        for (int j = i; j < n; ++j)
        {
            maximum = max (a[j], maximum);
            minimum = min (a[j], minimum);
            if (maximum - minimum > t) break;
            ans = max (ans, j - i + 1);
        }
    }
    cout << ans;
    return 0;
}