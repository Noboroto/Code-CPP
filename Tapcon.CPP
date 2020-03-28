#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void Init ()
{
    const string FileINP = "Tapcon" + (string)".INP";
    const string FileOUT = "Tapcon" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}


int n, k;
vector <int> a;
vector <int> ans;

void In_Hoan_Vi (int u)
{
    if (u == k)
    {
        for (int i = 0; i < k; ++i) cout << ans[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = u; i < n; ++i)
    {
        ans.push_back(a[i]);
        In_Hoan_Vi(u + 1);
        ans.pop_back();
    }
}

int main ()
{
    Init();
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    In_Hoan_Vi(0);
    return 0;
}