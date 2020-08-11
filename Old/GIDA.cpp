#include <iostream>
#include <algorithm>

using namespace std;

int const N = 1e5 + 7;
int a[N], b[N], n;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
    }
    sort (a + 1,a + 1 + n);
    sort( b + 1, b + 1 + n);
}

int main(){
    start();
    return 0;
}
