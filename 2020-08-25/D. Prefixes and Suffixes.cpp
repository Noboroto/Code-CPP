/*
https://codeforces.com/problemset/problem/432/D
*/

#include <bits/stdc++.h>

using namespace std;

vector <int> Prefix;
string s;
int n;
map <int, int> Counting;

vector <int> Get_Z (string s)
{
    int n = s.length();
    vector <int> ans (n);
    ans[0] = n;
    Counting[n]++;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
        {
            ans[i] = min (r - i + 1, ans[i - 1]);
        }
        while (i + ans[i] < n && s[ans[i]] == s[i + ans[i]])
            ++ans[i];
        if (i + ans[i] - 1 > r)
            l = i, r = i + ans[i] - 1;
        if (s[i] == s[0]) Counting[ans[i]]++;
    }
    return ans;
}

void Init ()
{
    cin >> s;
    n = s.length();
    Prefix = Get_Z(s);
    for (int i = n - 1; i >= 1; --i)
    {
        Counting[i] += Counting[i + 1];
    }
}

int main ()
{
    vector <int> ans;
    Init();
    for (int i = 1; i <= s.length(); ++i)
    {
        if (s[n - i] != s[0]) continue;
        if (Prefix[n - i] != i) continue;
        ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " " << Counting[ans[i]] << '\n';
    }
    return 0;
}