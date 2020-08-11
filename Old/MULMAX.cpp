#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector <int> duong, am;
int n;
long long ans, ad, aa, dd;

int main()
{
    freopen("MULMAX.INP", "r", stdin);
    freopen("MULMAX.OUT", "w", stdout);
    dd = -1e18 - 7;
    aa = dd;
    ad = aa;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (x < 0) am.push_back(x);
        else duong.push_back(x);
    }
    sort (duong.begin(), duong.end());
    sort (am.begin(), am.end());
    if (duong.size() >= 2) dd = duong[duong.size()-2]*duong.back();
    if (am.size() >= 2) aa = am[1]*am[0];
    if (duong.size() > 0 && am.size() > 0) ad = am[0]*duong.back();
    ans = max (dd, max (ad, aa));
    cout << ans;
    return 0;
}
