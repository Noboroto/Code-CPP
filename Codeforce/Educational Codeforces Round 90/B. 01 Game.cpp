#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "B" + (string)".INP";
    const string FileOUT = "B. 01 Game" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

void Solve (string s)
{
    int Counter = 1, mark = 0;
    bool ac = true;
    vector <char> ans;
    for (int i = 0; i < s.length(); ++i) ans.push_back (s[i]);
    while (!ans.empty())
    {
        for (int i = 1; i < ans.size(); ++i)
        {
            if (ans [i - 1] != ans [i]) 
            {
                mark = i - 1;
                ac = false;
                break;
            }
        }
        if (ac) break;
        else 
        {
            for (int i = mark; i < ans.size() - 2; ++i)
            {
                ans [i] = ans [i + 2];
            }
            ac = true;
            ans.pop_back();
            ans.pop_back();
        }
        Counter++;
    }
    if (Counter % 2 == 0) cout << "DA";
    else cout << "NET";
    cout << "\n";
}

int main ()
{
    //Init();
    int t;
    string s = "";
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> s;
        Solve (s);
    }
    return 0;
}