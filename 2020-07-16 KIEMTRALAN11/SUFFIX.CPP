#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "SUFFIX" + (string)".INP";
    const string FileOUT = "SUFFIX" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

string s, ans = "";
bool Checked[100];

int main ()
{
    Init();
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if (!Checked[(int)(s[i] - 'a')]) 
        {
            Checked[(int)(s[i] - 'a')] = true;
            ans += s[i];
        }
    }
    cout << ans;
    return 0;
}