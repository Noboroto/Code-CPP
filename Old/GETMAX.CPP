#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> a, b;


int main (){
    freopen ("GETMAX.INP", "r", stdin);
    freopen ("GETMAX.OUT", "w", stdout);
    int m, n;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int j = 0; j < m; ++j){
        int x;
        cin >> x;
        b.push_back (x);
    }
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());
    int ans;
    while (!a.empty())
    {
        ans = a.back();
        a.pop_back();
        if (binary_search (b.begin(), b.end(), ans)) break;
    }
    cout << ans;
    return 0;
}