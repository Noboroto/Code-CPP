#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    freopen ("LOGIN.INP", "r", stdin);
    freopen ("LOGIN.OUT", "w", stdout);
}

const int CH = 26;

struct Trie 
{
    vector <int> Ended;
    Trie *Child[CH];
    Trie ()
    {
        for (int i = 0; i < CH; ++i) Child[i] = NULL;
    }
    void Add (const string &s, int pos)
    {
        Trie *p = this;
        for (int i = 0; i < s.length(); ++i)
        {
            if ((*p).Child[s[i] - 'a'] == NULL) (*p).Child[s[i] - 'a'] = new Trie();
            p = (*p).Child[s[i] - 'a'];
        }
        (*p).Ended.push_back(pos);
    }

    vector<int> Counting (const string &s)
    {
        Trie *p = this;
        for (int i = 0; i < s.length(); ++i)
        {
            if ((*p).Child[s[i] - 'a'] == NULL) return vector<int>();
            p = (*p).Child[s[i] - 'a'];
        }
        return (*p).Ended;
    }
};

const int N = 2e4 + 1;
Trie Root;
int n;
bool Check[N][N];
string s[N];

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        Root.Add(s[i], i);
    }
    string tmp;
    int ans = 0;
    vector<int> ac;
    for (int i = 0; i < n; ++i)
    {
        for (int l = 0; l < s[i].size(); ++l)
        {
            tmp = "";
            for (int r = l; r < s[i].size(); ++r)
            {
                tmp += s[i][r];
                ac = Root.Counting(tmp);
                for (int j = 0; j < ac.size(); ++j)
                {
                    if (i == ac[j]) continue;
                    ans += !Check[i][ac[j]];
                    Check[i][ac[j]] = true;
                }
            }
        }
    }
    cout << ans;
    return 0;
}