#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("locker.INP", "r", stdin);
    freopen ("locker.OUT", "w", stdout);
}

bool CheckPalindrone (string s)
{
    int n = s.size() - 1;
    for (int i = 0; i <= n; ++i)
    {
        if (s[i] != s[n - i]) return false;
    }
    return true;
}

bool CheckAC (int a, int b, int _a, int _b, const string &s)
{
    swap (a, b);
    return (s[a] == s[_a] && s[b] == s[_b]);
}

int main ()
{
    Init();
    string s;
    cin >> s;
    if (CheckPalindrone(s)) cout << "YES";
    else
    {
        vector <pair <int, int> > a;
        int n = s.size();
        for (int i = 0; i < n / 2; ++i)
        {
            if (s[i] != s[n - i - 1]) a.push_back(make_pair(i, n - i - 1));
            if (a.size() > 2)
            {
                cout << "NO";
                return 0;
            }
        }
        if (a.size() == 1)
        {
            if (CheckAC(a[0].first, (n + 1) / 2 - 1, a[0].second, a[0].first, s)) cout << "YES";
            else if (CheckAC(a[0].second, (n + 1) / 2 - 1, a[0].first, a[0].second, s)) cout << "YES";
            else cout << "NO";
        }
        else
        {
            if (CheckAC(a[0].first, a[1].first, a[0].second, a[1].second, s)) cout << "YES";
            else if (CheckAC (a[0].first, a[1].second, a[0].second, a[1].first, s)) cout << "YES";
            else cout << "NO";
        }
        
    }
    return 0;
}