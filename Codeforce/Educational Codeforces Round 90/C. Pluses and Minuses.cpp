#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "C" + (string)".INP";
    const string FileOUT = "C. Pluses and Minuses" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

long long Solve (string s)
{
    long long n = 0, sum = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '+') sum++;
        else sum--;
        n = min (n, sum);
    }
    n = abs (n);
    long long ans = 0;
    for (long long i = 1; i <= n + 1; ++i)
    {
        ans += min ((long long)s.length(), i);
    }
    ans += max ((long long)(0), (long long)(s.length() - (n + 1)));
    return ans;
}

int main ()
{
    //Init();
    int t;
    string s; 
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> s;
        cout << Solve (s) << "\n";;
    }
    return 0;
}