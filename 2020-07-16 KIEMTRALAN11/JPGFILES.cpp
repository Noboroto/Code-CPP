#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "JPGFILES" + (string)".INP";
    const string FileOUT = "JPGFILES" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

vector <string> ans;
int n, m;

int main ()
{
    Init();
    cin >> n;
    string s = "";
    getline (cin, s);
    for (int i = 0; i < n; ++i)
    {
        getline (cin, s);
        ans.push_back(s);
    }
    int l, r;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> l >> r;
        for (int j = l - 1; j <= r - 1; ++j)
        {
            cout << ans[j] << '\n';
        }
    }
    return 0;
}