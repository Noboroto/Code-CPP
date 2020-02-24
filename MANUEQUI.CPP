#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <int> a, b;


int main (){
    freopen ("MANUEQUI.INP", "r", stdin);
    freopen ("MANUEQUI.OUT", "w", stdout);
    int m, n, s;
    cin >> n >> m >> s;
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
    sort (b.begin(), b.end());
    int ans = 0;
    while (!a.empty())
    {
        int x = s - a.back();
        a.pop_back();
        if (binary_search (b.begin(), b.end(), x)) ans++;
    }
    cout << ans;
    return 0;
}