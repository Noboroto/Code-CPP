#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct project {
    int thu, chi, lai, id;
    bool operator < (project b) {
        if (lai > 0){
            if (chi < b.chi) return true;
        }
        if (lai < 0){
            if (thu > b.thu) return true;
        }
        return false;
    }
};

const int N = 1e5 + 7;
project h [N];
vector <project> a, b;
int n;

int start (){
   // freopen("PRJCHAIN.INP", "r", stdin);
   // freopen("PRJCHAIN.OUT", "w", stdout);
    int s = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> h[i].chi;
        h[i].id = i;
    }
    for (int i = 1; i <= n; ++i){
        cin >> h[i].thu;
        h[i].lai = h[i].thu - h[i].chi;
        s += h[i].lai;
        if (h[i].lai >= 0) a.push_back(h[i]);
        else a.push_back(h[i]);
    }
    sort (a.begin(), a.end());
    sort (b.begin(), b.end());
    if (!b.empty()) s -= b.back().thu;
    else s -= a.back().thu;
    return abs (s);
}

int main(){
    int ans = start();
    cout << ans << endl;
    for (int i = 0; i < a.size(); ++i){
        cout << a[i].id << ' ';
    }
    for (int i = 0; i < b.size(); ++i){
        cout << b[i].id << ' ';
    }
    return 0;
}
