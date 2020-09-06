#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("abba.INP", "r", stdin);
    freopen ("abba.OUT", "w", stdout);
}

string Solve (string s, string t)
{

}

int main ()
{
    Init();
    string s, t, tmp;
    while (cin >> s)
    {
        t = "";
        for (int i = 0; i < s.length(); ++i) 
        {
            if (tmp[i] == ' ') break;
            s[i] = tmp[i];
        }
        for (int i = tmp.size() + 1; i < s.length(); ++i)
            t += tmp[i];
        cout << Solve (s, t) << "\n";
    }
    return 0;
}