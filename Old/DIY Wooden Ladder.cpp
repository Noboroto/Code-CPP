#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
int a [N], n, t;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
}

int solve (){
    int s = 0;
    s = min (a[n], a[n-1]) - 1;
    s = min (s, n - 2);
    return s;
}

int main(){
    cin >> t;
    for (int i = 1; i<= t; ++i){
        start();
        cout << solve() << endl;
    }
    return 0;
}
