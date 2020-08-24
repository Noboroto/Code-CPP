/*
https://codeforces.com/contest/1133/problem/A
*/
#include <bits/stdc++.h>

using namespace std;

struct OwnTime
{
    int Hour, Minute;
    OwnTime (int h = 0, int m = 0)
    {
        Hour = 0;
        Minute = 0;
    }
};

    OwnTime GetTime (const string &s)
    {
        OwnTime ans = OwnTime();
        ans.Hour = (s[0] - '0') * 10 + (s[1] - '0');
        ans.Minute = (s[3] - '0') * 10 + (s[4] - '0');
        return ans;
    }
    string GetString (const OwnTime &t)
    {
        string s = "";
        s += (t.Hour / 10) + '0';
        s += (t.Hour % 10) + '0';
        s += ":";
        s += (t.Minute / 10) + '0';
        s += (t.Minute % 10) + '0';
        return s;
    }

    OwnTime operator - (const OwnTime &a, const OwnTime &b)
    {
        OwnTime ans = OwnTime();
        ans.Minute = a.Minute - b.Minute + (a.Minute < b.Minute) * 60;
        ans.Hour = a.Hour - b.Hour - (a.Minute < b.Minute);
        if (a.Hour < b.Hour) 
            ans.Hour += 24;
        return ans;
    }

    OwnTime operator + (const OwnTime &a, const OwnTime &b)
    {
        OwnTime ans = OwnTime();
        ans.Minute = (a.Minute + b.Minute) % 60;
        ans.Hour = (a.Hour + b.Hour + ((a.Minute + b.Minute) / 60)) % 24; 
        return ans;
    }

    OwnTime GetMid (OwnTime a)
    {
        if (a.Hour == 0)
        {
            a.Minute /= 2;
        }
        else
        {
            a.Minute += (a.Hour % 2 != 0) * 60;
            a.Minute /= 2;
            a.Hour /= 2;
        }
        return a;
    }

OwnTime a, b;

void Init ()
{
    string s;
    cin >> s;
    a = GetTime (s);
    cin >> s;
    b = GetTime (s);
}

int main ()
{
    Init();
    OwnTime ans = b - a;
    ans = GetMid (ans);
    ans = ans + a;
    cout << GetString (ans);
    return 0;
}