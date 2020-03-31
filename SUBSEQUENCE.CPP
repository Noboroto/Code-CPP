#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "SUBSEQUENCE" + (string)".INP";
    const string FileOUT = "SUBSEQUENCE" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}

const int oo = 1e9 + 7;
int n, ans;
vector <int> tmp, result;

void BT (int u)
{
    if (u == n) return;
    for (int i = u + 1; i <= n; ++i)
    { 
        if (u != 0 && tmp[i] == tmp[result.back()]) continue;
        result.push_back(i);
        ans = (ans + 1) % oo;
        BT(i);
        result.pop_back();
    }
}

int main ()
{
    //Init();
    cin >> n;
    ans = 0;
    tmp.push_back(0);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        tmp.push_back(x);
    }
    BT(0);
    cout << ans;
    return 0;
}