#include <iostream>

using namespace std;

const int N = 60000, oo = 1e9 + 7;
int f[N], r[N], a[N], n;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        f[i] = oo;
    }
    for (int i = 1; i <= n - 1; ++i){
        cin >> r[i];
    }
}

void solve(int i){
    if (i <= 0) return oo;

}

int main(){
    return 0;
}
