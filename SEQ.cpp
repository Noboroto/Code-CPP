#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int l, r, n;
vector <int> Sum;

int main (){
    freopen ("SEQ.INP", "r", stdin);
    freopen ("SEQ.OUT", "w", stdout);
    cin >> n >> l >> r;
    Sum.push_back(0);
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        Sum.push_back (Sum[i - 1] + x);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; ++j){
            int tmp = abs(Sum[j] - Sum[i - 1]);
            if (l <= tmp && tmp <= r) ans++;
        }
    }
    cout << ans;
    return 0;
}