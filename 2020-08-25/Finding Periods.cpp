#include <bits/stdc++.h>
 
using namespace std;
 
vector <int> Get_Z (string s)
{
    int n = s.length();
    vector <int> ans (n);
    ans[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
        {
            ans[i] = min (r - i + 1, ans[i - l]);
        }
        while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]]) ++ans[i];
        if (i + ans[i] - 1 > r)
            l = i;
            r = i + ans[i] - 1;
    }
    return ans;
}
 
vector <int> Prefix;
string s;
 
void Init ()
{
    cin >> s;
    Prefix = Get_Z(s);
}
 
int main ()
{
    Init();
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] != s[0]) continue;
        if (Prefix[i] + i == s.length())
        cout << i << ' ';
    }
    cout << s.length();
    return 0;
}