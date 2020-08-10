#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector <int> t, r, f;
int n;

int main (){
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        t.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        r.push_back(x);
    }
    f.push_back (t[0]);
    f.push_back (min (t[0] + t[1], r[0]));
    for (int i = 2; i < n; ++i){
        int tmp = min (f[i - 1] + t[i], f[i - 2] + r[i - 1]);
        f.push_back(tmp);
    }
    cout << f.back();
    return 0;
}