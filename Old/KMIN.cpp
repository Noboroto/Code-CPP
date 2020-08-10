#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, k;
bool trung = false;

vector <int> a;

int main()
{
    freopen("KMIN.INP", "r", stdin);
    freopen("KMIN.OUT", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort (a.begin(), a.end());
    if (a[0] == a[1]) a[0] = 1e9 + 7;
    for (int i = 1; i < n; ++i){
        if (a[i] == a[i - 1]) {
            a[i - 1] = 1e9 + 7;
            if (i == n - 1) a[i] = 1e9 + 7;
            trung = true;
        } else if (trung){
            a[i - 1] = 1e9 + 7;
            trung = false;
        }
    }
    sort (a.begin(), a.end());
    for (int i = 0; i < k; ++i){
        cout << a[i] << endl;
    }
    return 0;
}
