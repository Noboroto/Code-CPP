#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "MAXV" + (string)".INP";
    const string FileOUT = "MAXV" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

bool Compare (const string &s, const string &t)
{
    return ((s + t) > (t + s));
}

const int N = 1e5 + 1;
int n;
string a[N];

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort (a, a + n, Compare);
    for (int i = 0; i < n; ++i) cout << a[i];
    return 0;
}