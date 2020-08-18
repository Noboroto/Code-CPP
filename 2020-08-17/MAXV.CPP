#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "MAXV" + (string)".INP";
    const string FileOUT = "MAXV" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

struct CompareString
{
    bool operator () ( string s,  string t)
    {
        bool lessfirst = s.length() < t.length();
        while (s.length() < t.length()) s +='0';
        while (t.length() < s.length()) t += '0';
        for (int i = 0; i < min (s.length(), t.length()); ++i)
        {
            if (s[i] < t[i]) return true;
            else if (s[i] > t[i]) return false;
        }
        return lessfirst;
    }
};

int n;
priority_queue<string, vector <string>, CompareString> a;
string s, t;

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        a.push(s);
    }
    while (a.size() > 1)
    {
        s = a.top();
        a.pop();
        t = a.top();
        a.pop();
        a.push (max (s + t, t + s));
    }
    cout << a.top();
    return 0;
}