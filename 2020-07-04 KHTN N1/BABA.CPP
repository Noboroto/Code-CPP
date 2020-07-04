#include <bits/stdc++.h>

using namespace std;

const int mod = 33;
string s;
int Problem, i, j;

string Max (string &a, int first, int last)
{
    string ans = "";
    if (a.length() > (last - first)) return a;
    else if  (a.length () < (last - first + 1)) 
    {
        for (int j = first; j < last; j++)
        {
            ans += s[j];
        }
        return ans;
    }
    for (int i = first; i < last; i++)
    {
        if (a[i - first] > s[i]) 
        {
            ans = a;
            break;
        }
        else if (a[i - first] < s[i]) 
        {
            for (int j = first; j < last; j++)
            {
                ans += s[j];
            }
            break;
        }
    }
    return ans;
}

int Solve_1 ()
{
    int tmp = 1;
    int ans = 0;
    for (i = 0; i < s.length(); ++i)
    {
        j = i;
        tmp = 0;
        for (j = i; j < s.length(); ++j)
        {
            tmp = ((tmp % mod) * 10 + (int)(s[j] - '0')) % mod;
            if (tmp == 0) 
            {
                ans++;
            }
        }
    }
    return ans;
}

string Solve_2 ()
{
    int tmp = 1;
    string ans = "", str = "";
    for (i = 0; i < s.length(); ++i)
    {
        j = i;
        tmp = 0;
        str = "";
        for (j = i; j < s.length(); ++j)
        {
            str += s[j];
            tmp = ((tmp % mod) * 10 + (int)(s[j] - '0')) % mod;
            if (tmp == 0) 
            {
                ans = Max (ans, i, j + 1);
            }
        }
    }
    return ans;
}

int main ()
{
    cin >> s;
    cin >> Problem;
    if (s.length() <= 1e3)
    {
        switch (Problem)
        {
        case 1:
            cout << Solve_1();
            break;
        case 2:
            cout << Solve_2();
            break;
        }
    }
    else 
    {
        if (Problem == 1) cout << 0;
        else cout << -1;
    }
    return 0;
}