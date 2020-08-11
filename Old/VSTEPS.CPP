#include <iostream>
#include <vector>

using namespace std;

const int N = 14062008;
vector <int> f;
vector <bool> Ok;
int n, t;

int main () {
    cin >> n >> t;
    for (int i = 0; i < n; ++i) Ok.push_back(true);
    for (int i = 0; i < t; ++i) {
        int x;
        cin >> x;
        Ok[x - 1] = false;
    }
    f.push_back(1);
    if (Ok[1]) f.push_back(1);
    else f.push_back (0);
    for (int i = 2; i < n;++i){
        if (!Ok[i]) f.push_back(0);
        else f.push_back((f[i - 1] + f[i - 2]) % N);
    }
    cout << f.back();
    return 0;
}