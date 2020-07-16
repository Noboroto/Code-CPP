#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "BASKET_B" + (string)".INP";
    const string FileOUT = "BASKET_B" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

int const N = 100 + 1;
int n, x, scoreA = 0, scoreB = 0;
string notice;
pair <int, int> SumA, SumB, previous;

pair <int, int> Decoding (string &s)
{
    return 
    make_pair((int)(s[0] - '0') * 10 + (int)(s[1] - '0'), 
            (int)(s[3] - '0') * 10 + (int)(s[4] - '0'));
}

pair <int, int> Plus (pair <int, int> a, pair <int, int> b)
{
    pair <int, int> ans;
    ans.first = a.first + b.first + (a.second + b.second > 60);
    ans.second = (a.second + b.second) % 60;
    return ans;
}

pair <int, int> Minus (pair <int, int> a, pair <int, int> b)
{
    pair <int, int> ans;
    ans.first = a.first - b.first - (a.second < b.second);
    ans.second = a.second + 60*(a.second < b.second) - b.second;
    return ans;
}

pair <pair <int, int>, int> f[N];

int main ()
{
    Init();
    cin >> n;
    for (int i = 0; i < n; ++i) 
    {
        cin >> x;
        cin >> notice;
        f[i] = make_pair (Decoding (notice), x);
    }
    sort (f, f + n);
    for (int i = 0; i < n; ++i)
    {
        if (scoreA == scoreB) previous = f[i].first;
        scoreA += (f[i].second == 1);
        scoreB += (f[i].second == 2);
        if (scoreA == scoreB)
        {
            SumA = (f[i].second != 1) ? Plus (SumA, Minus (f[i].first, previous)) : SumA;
            SumB = (f[i].second != 2) ? Plus (SumB, Minus (f[i].first, previous)) : SumB;
            previous = f[i].first;
        }
    }

    SumA = (scoreA > scoreB) ? Plus (SumA, Minus (make_pair(48,0), previous)) : SumA;
    SumB = (scoreA < scoreB) ? Plus (SumB, Minus (make_pair(48,0), previous)) : SumB;
    
    cout << ((SumA.first < 10) ? "0" : "") << SumA.first << ':' << ((SumA.second < 10) ? "0" : "") << SumA.second << '\n';
    cout << ((SumB.first < 10) ? "0" : "") << SumB.first << ':' << ((SumB.second < 10) ? "0" : "") << SumB.second << '\n';
    return 0;
}