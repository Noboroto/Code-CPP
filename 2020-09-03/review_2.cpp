#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("review.INP", "r", stdin);
    freopen ("review.OUT", "w", stdout);
}

map <char, queue <string> > AC;
int n, m;
vector <string> tmp;
string s;

int main ()
{
    Init();
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        tmp.push_back(s);
    } 
    sort (tmp.begin(), tmp.end());
    string ans = "";
    for (int i = 0; i < n; ++i) AC[tmp[i][0]].push(tmp[i]);
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        ans = AC[s[0]].front();
        cout << ans << "\n";
        AC[s[0]].pop();
        AC[s[0]].push(ans);
    }
    return 0;
}