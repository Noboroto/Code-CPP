#include <bits/stdc++.h>

using namespace std;

const int mod = 33;
string s;
int Problem, i, j;

string Max (string &a, string &b)
{
    if (a.length() > b.length()) return a;
    else if  (a.length () < b.length()) return b;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] > b[i]) return a;
        else if (a[i] < b[i]) return b;
    }
    return b;
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
            tmp = ((tmp % mod) * 10 + (int)(s[j] - '0')) % mod;
            str += s[j];
            if (tmp == 0) 
            {
                ans = Max (ans, str);
            }
        }
    }
    return ans;
}

int main ()
{
    cin >> s;
    cin >> Problem;
    switch (Problem)
    {
    case 1:
        cout << Solve_1();
        break;
    case 2:
        cout << Solve_2();
        break;
    }
    return 0;
}