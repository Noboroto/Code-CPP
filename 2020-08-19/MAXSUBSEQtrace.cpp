#include <bits/stdc++.h>

using namespace std;

void Init ()
{
    const string FileINP = "MAXSUBSEQtrace" + (string)".INP";
    const string FileOUT = "MAXSUBSEQtrace" + (string)".OUT";
    freopen (FileINP.c_str(), "r", stdin);
    freopen (FileOUT.c_str(), "w", stdout);
}
const int N = 5e3 + 1;
int n, l, r;
int sum[N];
int ans;
pair <int, int> node;

int main ()
{
    Init();
    cin >> n >> l >> r;
    l--;
    r--;
    ans = -1e9 - 7;
    for (int i = 1; i <= n; ++i) 
    {
        cin >> sum[i];
        sum[i] += sum [i - 1];
        if (i <= l)
        {
            if (ans < sum[i]) 
            {
                ans = sum[i];
                node = make_pair(1, i);
            }
        }
    }
    for (int i = l; i <= n; ++i)
    {
        
    }
    cout << ans << '\n';
    cout << node.first << ' ' << node.second;
    return 0;
}