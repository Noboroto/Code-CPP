#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int oo = (int)('a');

int n;
int SoLuong [510][28];
vector <int> ab[100];

void Process (int k, string c, string s){
    int l, r, dis = 0;
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n;++j){
            bool Check = true;
            if (j - i + 1 <= dis) continue;
            for (int t = 1; t < k; ++t) {
                int valueA = (int)c[t] - oo;
                int valueB = (int)c[t-1]-oo;
                int solA = SoLuong[j][valueA] - SoLuong[i][valueA] + (int)(s[i]==c[t]);
                int solB = SoLuong[j][valueB] - SoLuong[i][valueB] + (int)(s[i]==c[t-1]);
                if (solA != solB) {
                    Check = false;
                    break;
                }
            }
            if (Check){
                dis = j - i + 1;
                l = i;
                r = j;
            }
        }
    }
    if (dis == 0) cout << -1 << '\n';
    else cout << l + 1 << ' ' << r + 1 << '\n';
}

int main () {
    //freopen ("EQUQNT.INP", "r", stdin);
    //freopen ("EQUQNT.OUT", "w", stdout);
    int k, q; 
    string c, s;
    cin >> n;
    cin >> s;
    cin >> q;
    for (int i = 0; i < n; ++i){
        int valueC = (int)s[i] - oo;
        for (int j = i; j < n; ++j) SoLuong[j][valueC]++;
    }
    while (q > 0)
    {
        cin >> k >> c;
        Process(k,c,s);
        q--;
    }
    return 0;
}