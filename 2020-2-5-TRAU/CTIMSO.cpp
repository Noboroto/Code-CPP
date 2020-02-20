#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int oo = 2e5;
bool UNT[oo];

void SNT (){
    fill(UNT, UNT + oo, true);
    for (int i = 2; i <= oo; ++i){
        if (!UNT[i]) continue;
        for (int j = i*2; j <= oo; j+=i){
            UNT[j] = false;
        }
    }
}

int main (){
    //freopen ("CTIMSO.INP", "r", stdin);
    //freopen ("CTIMSO.OUT", "w", stdout);
    int n, m, k = oo, giaithua = 1;
    cin >> n >> m;
    SNT();
    int PTA[oo], PTB[oo];
    fill(PTA, PTA + oo, 0);
    fill(PTB, PTB + oo, 0);
    for (int i = 2; i <= oo; ++i){
        while (m % i == 0)
        {
            m /= i;
            PTB[i]++;
        }
        if (m == 1) break;
    }
    for (int t = 2; t <= n; ++t){
        int j = t;
        for (int i = 2; i <= t; ++i){
            while (j % i == 0)
            {
                j /= i;
                PTA[i]++;
            }
            if (j == 1) break;
        }
    }
    for (int i = 2; i <= oo; ++i){
        if (PTB[i] == 0) continue;
        k = min (k, PTA[i]/ PTB[i]);
    }
    if (k == oo) k = 0;
    cout << k;
    return 0;
}