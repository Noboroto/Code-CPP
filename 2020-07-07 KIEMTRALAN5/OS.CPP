#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "OS" + (string)".INP";
    const string FileOUT = "OS" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    //freopen (FileOUT.c_str(), "w", stdout);
}

struct Mem 
{
    int u, v, c;
    Mem (int _u = 0, int _v = 0, int _c = 0)
    {
        u = _u;
        v = _v;
        c = _c;
    }
    bool operator < (Mem &b)
    {
        if (u < b.u) return true;
        if (u == b.u && c < b.c) return true;
        if (u == b.u && c == b.c && v < b.v) return true;
        return false; 
    } 
};

int n, m;
vector <Mem> a;

int main ()
{
    int u, v;
    Init();
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> u >> v;
        if (u <= m) a.push_back (Mem(u, i, -1));
        if (v <= m) a.push_back (Mem(v, i, 1));
    }
    sort (a.begin(), a.end());
    int sum = 0, prev = -1;
    for (int i = 0; i < a.size (); ++i)
    {
        if (prev != a[i].c && prev != a[i].v) continue;
        sum+=(i!=0);
        prev = -1;
    }
    cout << sum;
    return 0;
}