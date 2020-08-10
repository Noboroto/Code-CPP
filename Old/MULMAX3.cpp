#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector <int> duong, am;
int n;
long long ans, add, aaa, ddd, aad;

int main()
{
    freopen("MULMAX3.INP", "r", stdin);
    freopen("MULMAX3.OUT", "w", stdout);
    ddd = -1e18 - 7;
    aaa = ddd;
    add = aaa;
    aad = add;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (x < 0) am.push_back(x);
        else duong.push_back(x);
    }
    sort (duong.begin(), duong.end());
    sort (am.begin(), am.end());
    if (duong.size() >= 3) ddd = duong[duong.size()-2]*duong.back()*duong[duong.size()-3];
    if (am.size() >= 3) aaa = am[am.size()-2]*am.back()*am[am.size()-3];
    if (duong.size() > 0 && am.size() > 1) aad = duong.back()*am[0]*am[1];
    if (duong.size() > 1 && am.size() > 0) add = duong.back()*am[0]*duong[duong.size()-2];
    ans = max (aaa, add);
    ans = max (ans, max (ddd, aad));
    cout << add << ' ' << aad << ' ' << ddd << ' ' << aaa << ' ' << ans;
    return 0;
}
