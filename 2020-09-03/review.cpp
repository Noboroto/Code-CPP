#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("review.INP", "r", stdin);
    freopen ("review.OUT", "w", stdout);
}

const int N = 1e5 + 1;
vector < vector <string> > AC (26, vector<string>());
map <int, int> Counting;
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
    for (int i = 0; i < n; ++i) AC[tmp[i][0] - 'a'].push_back(tmp[i]);
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        cout << AC[s[0] - 'a'][Counting[s[0] - 'a']] << '\n';
        Counting[s[0] - 'a']++;
        Counting[s[0] - 'a'] %= AC[s[0] - 'a'].size();
    }
    return 0;
}