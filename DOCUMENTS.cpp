#include <iostream>
#include <cstdio>

using namespace std;

struct point {
    int d, c;
    point (int _d = 0, int _c = 0){
        d = _d;
        c = _c;
    }
};

const int N = 1e5 + 7;
point tmp [N];
int n;

void start (){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        tmp[i] = point (a + b, c);
    }
}

int main(){
    cout << "NO";
    return 0;
}
