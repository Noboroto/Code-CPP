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
int n;

int main ()
{
    //Init();
    cin >> n;
    int ans = 0;
    int tmp = n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        ans += tmp;
        ans %= oo;
        tmp--;
    }
    cout << ans + 1;
    return 0;
}