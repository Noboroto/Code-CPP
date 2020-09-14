#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("DEL_STR.INP", "r", stdin);
    freopen ("DEL_STR.OUT", "w", stdout);
}

map <char, int> Checked;
string s, t, ans;
int MinCount;
char Will;

int main ()
{
    Init();
    cin >> s; 
    cin >> t;
    MinCount = 1e9 + 7;
    for (int i = 0; i < (int)t.length(); ++i) 
    {
        Checked[t[i]]++;
    }
    for (int i = 0; i < (int)t.length(); ++i) 
    {
        if (Checked[t[i]] < MinCount)
        {
            MinCount = Checked[t[i]];
            Will = t[i];
        }
    }
    ans = "";
    for (int i = 0; i < (int)s.length(); ++i)
    {
        if (s[i] == Will) continue;
        ans += s[i];
    }
    cout << ans;
    return 0;
}