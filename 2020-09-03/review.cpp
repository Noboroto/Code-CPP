#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("review.INP", "r", stdin);
    freopen ("review.OUT", "w", stdout);
}

const int N = 1e5 + 1;
queue <string> AC[26];
int n, m;
string tmp[N], s;

int main ()
{
    Init();
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp[i];
    } 
    sort (tmp, tmp + n);;
    string ans = "";
    for (int i = 0; i < n; ++i) AC[tmp[i][0] - 'a'].push(tmp[i]);
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        ans = AC[s[0] - 'a'].front();
        cout << ans << "\n";
        AC[s[0]-'a'].pop();
        AC[s[0]-'a'].push(ans);
    }
    return 0;
}