/*
https://codeforces.com/contest/888/problem/C
*/

#include <bits/stdc++.h>

using namespace std;

int ans;
string s;

bool Check (int k)
{
    bool OK = false, tmp;
    map <char, int> t;
    for (char i = 'a'; i <= 'z'; ++i)
    {
        tmp = true;
        for (int j = 0; j < k; ++j) t[s[j]]++;
        if (t[i] == 0) 
        {
            t.clear();
            continue;
        }
        for (int j = k; j < s.length(); ++j)
        {
            t[s[j]]++;
            t[s[j - k]]--;
            if (t[i] == 0)
            {
                tmp = false;
                t.clear();
                break;
            }
        }
        OK = OK || tmp;
    }
    return OK;
}

int BS (int l, int r)
{
    int g, ans;
    while (l < r)
    {
        g = (l + r) / 2;
        if (Check (g)) 
            r = g - 1;
        else 
            l = g + 1;
    }
    return (Check(r)) ? r : r + 1;
}

int main ()
{
    cin >> s;
    ans = BS (1, s.length());
    cout << ans;
    return 0;
}